DIST = text
DISTPATH = text
LANG = c++
.include	<../Makefile.inc>

#compiling options
.PHONY:	build clean

build:	main.cpp

clean: 	
	rm -fv *.o
main.cpp: ../hanoi.o functions.o
	$(CC) $(CFLAGS) -o $(NAME).bin $@

functions.o: functions.h