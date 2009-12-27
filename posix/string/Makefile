NAME=string
LANG=c
.include	<../../Makefile>

#compiling options
.PHONY:	clean

$(NAME):
string.o: string.c
string.c: string.h

mycheck: lint
	splint -strict-lib -showcolumn -showfunc -strict -isoreserved -namechecks *.c *.h
lint: 
	lint -aabcehprsxH -I /usr/local/include/ *.c *.h | grep -v "//"
