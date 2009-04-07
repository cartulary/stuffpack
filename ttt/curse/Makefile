CC := g++
CFLAGS := -g -pipe
#perhaps we should replace -ansi with -std=c++98 
CFLAGS += -Wall -Wextra -ansi -pedantic -Wabi -Weffc++
CFLAGS += -Wformat=2 -Wformat-y2k -Wformat-nonliteral -Wformat-security
CFLAGS += -Wctor-dtor-privacy -Wnon-virtual-dtor -Wstrict-null-sentinel -Wswitch-default -Wunused-parameter -Wstrict-null-sentinel -Woverloaded-virtual -Wsign-promo
CFLAGS += -ffor-scope
LDFLAGS += -lncurses

#compiling options
.PHONY:	all clean

all:	ttt tttboard.o

ttt.o:

tttboard.o: tttboard.cpp

clean: 	
	rm -fv *.o
	rm -fv ./ttt
