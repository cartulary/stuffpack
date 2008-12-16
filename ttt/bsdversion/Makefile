CC := g++
CFLAGS := -g -pipe
CFLAGS += -Wall -Wextra -ansi -pedantic -Wabi -Weffc++
CFLAGS += -Wformat=2 -Wformat-y2k -Wformat-nonliteral -Wformat-security
CFLAGS += -Wctor-dtor-privacy -Wnon-virtual-dtor -Wstrict-null-sentinel -Wswitch-default -Wunused-parameter -Wstrict-null-sentinel -Woverloaded-virtual -Wsign-promo
CFLAGS += -ffor-scope

#compiling options
.PHONY:	all clean
all:		ttt.cpp
	$(CC) $(CFLAGS) -o ttt-text ttt.cpp

clean: 	
	rm -fv *.o

ttt.o: ttt.h