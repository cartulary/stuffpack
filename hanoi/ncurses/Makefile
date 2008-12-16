DIST = ncurses
DISTPATH = ncurses
LANG = c++
.include	<../Makefile.inc>
CFLAGS += -lncurses

#compiling options
.PHONY:	build clean

build:	main.o 
	CC $(CFLAGS) -o $(NAME).bin main.cpp
clean: 	
	-rm -rfv *.o

main.cpp: ../hanoi.o functions.o