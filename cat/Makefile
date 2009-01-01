NAME=cat
LANG = c++
.include	<../Makefile>

#compiling options
.PHONY:	build clean

build:	cat.cpp
	$(CC) $(CFLAGS) -o $(NAME).bin cat.cpp

clean: 	
	rm -fv *.o
