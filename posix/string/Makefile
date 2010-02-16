NAME=doTest
LANG=c
USE_CUNIT=yes
USE_NCURSES=yes
.include	<../../Makefile>

REAL_STRING ?= 0
.ifdef $(REAL_STRING) == 1
CFLAGS+= -DREAL_STRING
.endif

#compiling options
.PHONY:	clean

$(NAME): string.o doTest.o
string.o: string.c
string.c: string.h
doTest.o: doTest.c
doTest.c: doTest.h

mycheck: lint
	splint -strict-lib -showcolumn -showfunc -strict -isoreserved -namechecks *.c *.h
lint: 
	lint -aabcehprsxH -I /usr/local/include/ *.c *.h | grep -v "//"
