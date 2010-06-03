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
NEED_RTTI?=no
NEED_THREADSAFE?=no

CFLAGS = -pipe
.ifdef $(DEBUG) == on
CFLAGS += -g3
.else
CFLAGS += -O3
.endif

.ifdef $(LANG) == c++
#we are using c++ add the flags that only work for c++
CC = llvm-g++
CFLAGS += -std=c++0x -Wabi
CFLAGS += -Weffc++
CFLAGS += -fno-gnu-keywords
CFLAGS += -Wstrict-null-sentinel -Wctor-dtor-privacy -Wnon-virtual-dtor -Woverloaded-virtual -Wsign-promo -Wold-style-cast
#max template depth that could be relied on is 17
CFLAGS += -ffor-scope -fuse-cxa-atexit -ftemplate-depth-17 -fuse-cxa-atexit
.elif $(LANG) == c
CC = llvm-gcc
CFLAGS += -combine
CFLAGS += -std=c99 
CFLAGS += -Wimplicit-function-declaration -Wbad-function-cast -Wdeclaration-after-statement
CFLAGS += -Wstrict-prototypes -Wold-style-definition -Wmissing-prototypes
CFLAGS += -Wmissing-declarations -Wnested-externs
.endif

# set the global flags
CFLAGS += -Wall -Wextra -pedantic
#change the "4" to a lower level - maybe?
CFLAGS += -Wformat=2 -Wstrict-aliasing=2 -Wstrict-overflow=4
CFLAGS += -Wunused -Wunused-parameter -Wswitch-default -Wswitch-enum 
CFLAGS += -Winit-self -Wmissing-include-dirs -Wpointer-arith -Wconversion
CFLAGS += -Wfloat-equal -Wundef -Wshadow -Wcast-qual -Wcast-align -Wwrite-strings
CFLAGS += -fabi-version=0 -funswitch-loops  #-fprefetch-loop-arrays #-funroll-loops 
CFLAGS += -Winline -Wmissing-noreturn -Wpacked -Wpadded -Wredundant-decls
CFLAGS += -Wno-write-strings -Waggregate-return -Winvalid-pch -Wlong-long
CFLAGS += -Wvariadic-macros -Wstack-protector -Wvolatile-register-var
CFLAGS += -Wmissing-format-attribute
#CFLAGS += -Wlogical-op -Wnormalized=nfc
CFLAGS += -Wimport -Wunused-macros

#-Wunreachable-code is disabled for way too many false postives

INCLUDE_FILES = -I/usr/local/include
# Default includes...
CFLAGS += -isystem /usr/local/include
LDFLAGS = -L/usr/local/lib

.ifdef $(COMPILER) == clang
.if $(LANG) == c
CC = clang
CFLAGS += -Wextra-tokens
.elifdef $(LANG) == c++
CC = clang++
.else
.error clang be used for $(LANG)
.endif
.endif

.ifdef $(LANG) == java
CC = javac
CFLAGS=-deprecation -Xlint
SRCFILE=$(NAME).java
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

.ifdef $(USE_GFILT) == yes
#we first sneak the compiler name as a option to gfilt and replace the compiler with gfilt
CLFAGS = $(CC) $(CLFAGS)
CC=gfilt
.endif

.ifdef $(USE_OPENMP) == yes && $(COMPILER) == llvm
CFLAGS += -fopenmp
.endif

.ifdef $(NEED_RTTI) != yes && $(LANG) != java
CFLAGS += -fno-rtti
.endif

.ifdef $(NEED_THREADSAFE) != yes && $(LANG) != java
CFLAGS += -fno-threadsafe-statics
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
javaclean: .NOTMAIN .USE .EXEC .IGNORE .PHONY
	rm -fv ./*.class 
remake: .NOTMAIN .USE .EXEC .IGNORE .PHONY clean all

.if ! target(clean)
.ifdef $(LANG) != java
clean: .NOTMAIN .PHONY .IGNORE nameclean coreclean objclean
.else
clean: .NOTMAIN .PHONY .IGNORE nameclean javaclean
.endif
.endif

.if ! target($(NAME))
$(NAME):
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
