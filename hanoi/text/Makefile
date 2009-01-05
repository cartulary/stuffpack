DIST = text
DISTPATH = text
LANG = c++
.include	<../Makefile.inc>

#compiling options
.PHONY:	build clean

build:	main

main:	../hanoi.cpp functions.cpp main.cpp

functions.o: functions.h

clean:
	rm -fv *.o main