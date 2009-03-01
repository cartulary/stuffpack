NAME=icebreaker
LANG = c++
.include    <../Makefile>

#compiling options
.PHONY: all clean

all:  $(NAME) terrain.o

$(NAME): icebreaker.cpp terrain.cpp

terrain: terrain.o

clean:
	rm -fv *.o
	rm -f ./$(NAME) ./$(NAME).core

