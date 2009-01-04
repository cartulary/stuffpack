NAME=yes
LANG = c
.include	<../Makefile>

#compiling options
.PHONY:	build clean

build:	yes.c
	$(CC) $(CFLAGS) -o $(NAME).bin yes.c

clean: 	
	rm -fv *.o
