# To protect us from stupid errors (like running make nameclean in the root directory)
NAME?=DOES_NOT_EXIST
.if $(NAME) == DOES_NOT_EXIST
.error Can't work from global makefile - please call make in a project
.endif
LANG?=none
DEBUG?=off
COMPILER?=llvm

USE_NCURSES?=no
USE_GMP?=no
USE_HELLO?=no
USE_CUNIT?=no
USE_EDITLIB?=no
USE_LIBMAGIC?=no
USE_FLTK?=no
USE_OPENMP?=no
USE_PTHREAD?=no
USE_GFILT?=no

CFLAGS = -g3 -pipe
.ifdef $(DEBUG) == on
.else
CFLAGS += -O3
.endif

.ifdef $(LANG) == c++
#we are using c++ add the flags that only work for c++
CC = llvm-g++
CFLAGS += -ansi -Wabi
CFLAGS += -Weffc++
CFLAGS += -fno-gnu-keywords
CFLAGS += -Wstrict-null-sentinel -Wctor-dtor-privacy -Wnon-virtual-dtor -Woverloaded-virtual -Wsign-promo -Wold-style-cast
CFLAGS += -ffor-scope
.elif $(LANG) == c
CC = llvm-gcc
CFLAGS += -g
CFLAGS += -std=c99 
CFLAGS += -Wimplicit-function-declaration -Wbad-function-cast -Wdeclaration-after-statement
CFLAGS += -Wstrict-prototypes -Wold-style-definition -Wmissing-prototypes -Wmissing-declarations -Wnested-externs
.endif

# set the global flags
CFLAGS += -Wall -Wextra -pedantic
CFLAGS += -Wformat=2 -Wformat-y2k -Wformat-nonliteral -Wformat-security
CFLAGS += -Wunused -Wunused-parameter -Wswitch-default -Wswitch-enum 
CFLAGS += -Winit-self -Wmissing-include-dirs -Wpointer-arith -Wconversion
CFLAGS += -Wfloat-equal -Wundef -Wshadow -Wcast-qual -Wcast-align -Wwrite-strings
CFLAGS += -fabi-version=0 -funroll-loops 
CFLAGS += -Winline -Wmissing-noreturn -Wpacked -Wpadded -Wredundant-decls
#CFLAGS += -Wlogical-op -Wnormalized=nfc

INCLUDE_FILES = -I/usr/local/include
# Default includes...
CFLAGS += -isystem /usr/local/include
LDFLAGS = -L/usr/local/lib

.ifdef $(COMPILER) == clang && $(LANG) == c
CC = clang
CFLAGS = -std=c99 -pedantic -pedantic-errors $(INCLUDE_FILES)
CFLAGS += -Wall -Wextra -Wunused
CFLAGS += -Wextra-tokens -Wformat -Wcomment -Wendif-labels
LDFLAGS = -L/usr/local/lib
.endif
.ifdef $(COMPILER) == clang && $(LANG) != c
.error clang can't be used with non C sources
.endif


WANT_LIBS=

.if $(USE_HELLO) == yes
INCLUDE_FILES += -I../libhello -I ../../libhello
CFLAGS += $(INCLUDE_FILES)
LDFLAGS += -L../libhello/ -L../../libhello
WANT_LIBS += hello
.endif

.if $(USE_NCURSES) == yes
WANT_LIBS += ncurses
.endif

.if $(USE_CUNIT) == yes
WANT_LIBS += cunit curses
.endif

.if $(USE_GMP) == yes
.if $(LANG) == c++
WANT_LIBS += gmpxx
.endif
WANT_LIBS += gmp
.endif

.if $(USE_EDITLIB) == yes
WANT_LIBS	+=	edit termcap
.endif

.if $(USE_LIBMAGIC) == yes
WANT_LIBS += magic
.endif

.if $(USE_PTHREAD) == yes
WANT_LIBS += pthread
.endif

.if $(USE_FLTK) == yes || $(USE_FLTK) == 1
EXTRA_CFLAGS != fltk-config --use-forms --cxxflags --libs
CFLAGS += $(EXTRA_CFLAGS)

EXTRA_LDFLAGS != fltk-config --use-forms --ldflags --libs
LDFLAGS += $(EXTRA_LDFLAGS)
.endif

.if $(USE_FLTK) == 2
EXTRA_CFLAGS != fltk2-config --use-forms --cxxflags --libs
CFLAGS += $(EXTRA_CFLAGS)

EXTRA_LDFLAGS != fltk2-config --use-forms --ldflags --libs
LDFLAGS += $(EXTRA_LDFLAGS)
.endif

.if $(USE_GFILT)
#we first sneak the compiler name as a option to gfilt and replace the compiler with gfilt
CLFAGS = $(CC) $(CLFAGS)
CC=gfilt
.endif

.if (USE_OPENMP) && $(COMPILER) == llvm
CFLAGS += -fopenmp
.endif

.for LIB in $(WANT_LIBS)
LDFLAGS += -l$(LIB)
.endfor 

PREFIX = /usr/local

nameclean: .NOTMAIN .USE .EXEC .IGNORE .PHONY
	rm -f ./$(NAME)
coreclean: .NOTMAIN .USE .EXEC .IGNORE .PHONY
	rm -f ./$(NAME).core
objclean: .NOTMAIN .USE .EXEC .IGNORE .PHONY
	rm -fv ./*.o
.if ! target(clean)
clean: .NOTMAIN .PHONY .IGNORE nameclean coreclean objclean
.endif
.if ! target(all)
all: $(NAME)
.endif

rebuild: .NOTMAIN .PHONY clean $(NAME)

check: .NOTMAIN
	## only run this on C++ code
.if $(LANG) == c++
	cppcheck --enable=all $(INCLUDE_FILES) -j2 -v  *.cpp
.endif
## only run these on C code....
.if $(LANG) == c
	splint -strict-lib -showcolumn -showfunc -strict *.c *.h
	lint -aabcehprsxH $(INCLUDE_FILES) *.c *.h
.endif
	## run on all code...
	rats -rw3 *
