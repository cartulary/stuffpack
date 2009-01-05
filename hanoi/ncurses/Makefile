DIST = ncurses
DISTPATH = ncurses
LANG = c++
.include	<../Makefile.inc>
CFLAGS += -lncurses 

#compiling options
.PHONY:	build clean

build:	main

main:	../hanoi.cpp functions.cpp main.cpp

functions.o: functions.h

clean:
	rm -fv *.o main