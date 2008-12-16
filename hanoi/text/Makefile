DIST = text
DISTPATH = text
LANG = c++
.include	<../Makefile.inc>
#compiling options
.PHONY:	build clean

build:	main.o 
	CC $(CCFLAGS) -o $(NAME).bin main.cpp
clean: 	
	-rm -rfv *.o

main.cpp: ../hanoi.o functions.o
functions.o: functions.h