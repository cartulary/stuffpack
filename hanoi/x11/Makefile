DIST = x11
DISTPATH = x11
LANG = c++
.include	<../Makefile.inc>
#CFLAGS += -lpdcurses 

main: ../hanoi.o functions.o main.cpp
	$(CC) $(CFLAGS) -o $(NAME).bin $@

functions.o: functions.h