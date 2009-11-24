# To protect us from stupid errors (like running make nameclean in the root directory)
NAME?=DOES_NOT_EXIST
LANG?=none
DEBUG?=off
COMPILER?=llvm

USE_NCURSES?=no
USE_GMP?=no

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
CFLAGS += -Wunreachable-code -Winline -Wmissing-noreturn -Wpacked -Wpadded -Wredundant-decls

# Default includes...
CFLAGS += -isystem /usr/local/include
LDFLAGS = -L/usr/local/lib

.if $(USE_NCURSES) == yes
LDFLAGS += -lncurses
.endif

.if $(USE_GMP) == yes
.if $(LANG) == c++
LDFLAGS += -lgmpxx
.endif
LDFLAGS += -lgmp
.endif


.ifdef $(COMPILER) == clang && $(LANG) == c
CC = clang
CFLAGS = -std=c99 -pedantic-errors -I /usr/local/include -Wall
CFLAGS += -Wall -Wextra -Wendif-labels -Wunused
LDFLAGS = -L/usr/local/lib
.endif

PREFIX = /usr/local

nameclean: .NOTMAIN .USE .PHONY
	rm -f ./$(NAME)
coreclean: .NOTMAIN .USE .PHONY
	rm -f ./$(NAME).core
objclean: .NOTMAIN .USE .PHONY
	rm -fv ./*.o

check: .NOTMAIN
	## only run this on C++ code
	cppcheck -v -a -s --unused-functions .
	## run on all code...
	#rats -rw3 *
	## only run these on C code....
	#splint -strict-lib -showcolumn -showfunc -strict *.c *.h
	#lint -aabcehprsxH -I /usr/local/include/ *.c *.h