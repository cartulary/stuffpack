NAME=string
LANG=c
USE_CUNIT=yes
USE_NCURSES=yes
.include	<../../Makefile>

#compiling options
.PHONY:	clean

doTest: string.o doTest.c
string.o: string.c
string.c: string.h

mycheck: lint
	splint -strict-lib -showcolumn -showfunc -strict -isoreserved -namechecks *.c *.h
lint: 
	lint -aabcehprsxH -I /usr/local/include/ *.c *.h | grep -v "//"
