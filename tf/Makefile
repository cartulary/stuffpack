LANG = c
.include	<../Makefile>

#compiling options
.PHONY:	build clean

all:	true.o false.o

true:
	$(CC) $(CFLAGS) -o true.bin true.c

false:
	$(CC) $(CFLAGS) -o false.bin false.c

clean: 	
	rm -fv *.o
