NAME=pong
CC = llvm-g++
CFLAGS = -g3 -pipe -ansi -Wabi
CFLAGS += -Weffc++ -fno-gnu-keywords -Wstrict-null-sentinel -Wctor-dtor-privacy -Wnon-virtual-dtor -Woverloaded-virtual -Wsign-promo -ffor-scope
CFLAGS += -Wall -Wextra
CFLAGS += -Wformat=2 -Wformat-y2k -Wformat-nonliteral -Wformat-security
CFLAGS += -Wunused -Wunused-parameter -Winit-self -Wmissing-include-dirs -Wfloat-equal
CFLAGS += -Wfloat-equal -Wundef -Wshadow -Wcast-qual -Wcast-align -fabi-version=0 -funroll-loops
CFLAGS += -Wunreachable-code -Winline
CFLAGS += -I/usr/local/include -L/usr/local/lib -L/usr/local/lib -Wl,--export-dynamic -pthread -lalleg -lalleg_unsharable



#compiling options
.PHONY:     clean

all:  $(NAME)

$(NAME):

clean:
	rm -fv *.o
	rm -fv ./$(NAME)

