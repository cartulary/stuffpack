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
CFLAGS += -Wstrict-prototypes -Wold-style-definition -Wmissing-prototypes -Wmissing-declarations
.endif

# set the global flags
CFLAGS += -Wall -Wextra -pedantic
CFLAGS += -Wformat=2 -Wformat-y2k -Wformat-nonliteral -Wformat-security
CFLAGS += -Wunused -Wunused-parameter -Wswitch-default -Wswitch-enum 
CFLAGS += -Winit-self -Wmissing-include-dirs -Wpointer-arith -Wconversion
CFLAGS += -Wfloat-equal -Wundef -Wshadow -Wcast-qual -Wcast-align -Wwrite-strings
CFLAGS += -fabi-version=0 -funroll-loops
CFLAGS += -Winline -Wmissing-noreturn -Wpacked -Wpadded -Wredundant-decls

# Default includes...
CFLAGS += -isystem /usr/local/include
LDFLAGS = -L/usr/local/lib

WANT_LIBS=

.if $(USE_HELLO) == yes
CFLAGS += -I../libhello/ -I../../libhello
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

.if $(USE_FLTK) == yes
EXTRA_CFLAGS != fltk-config --use-forms --cxxflags --libs
CFLAGS += $(EXTRA_CFLAGS)

EXTRA_LDFLAGS != fltk-config --use-forms --ldflags --libs
LDFLAGS += $(EXTRA_LDFLAGS)
.endif

.for LIB in $(WANT_LIBS)
LDFLAGS += -l$(LIB)
.endfor 


.ifdef $(COMPILER) == clang && $(LANG) == c
CC = clang
CFLAGS = -std=c99 -pedantic-errors -I /usr/local/include -Wall
CFLAGS += -Wall -Wextra -Wendif-labels -Wunused
LDFLAGS = -L/usr/local/lib
.endif

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
	cppcheck -v -a -s --unused-functions *.cpp
.endif
.if $(LANG) == c
	splint -strict-lib -showcolumn -showfunc -strict *.c *.h
	lint -aabcehprsxH -I /usr/local/include/ *.c *.h
.endif
	## run on all code...
	#rats -rw3 *
	## only run these on C code....
