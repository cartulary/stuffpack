DIST = x11
DISTPATH = x11
LANG = c++
.include	<../Makefile.inc>
#CFLAGS += -lpdcurses 

#compiling options
.PHONY:	build clean

build:	main.cpp

clean: 	
	rm -fv *.o
main.cpp: ../hanoi.o functions.o
	$(CC) $(CFLAGS) -o $(NAME).bin $@

functions.o: functions.h