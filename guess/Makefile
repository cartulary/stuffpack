NAME = guess

DIST = guess
DISTPATH = .
LANG = c++
.include <../Makefile>
CFLAGS += -fno-threadsafe-statics 

#compiling options
.PHONY:	clean
build:	guess.cpp 

guess.cpp:
	$(CC) $(CFLAGS) -o $(NAME).bin $@

clean:
	rm -fv *.o


