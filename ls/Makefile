NAME=ls
LANG = c++
.include	<../Makefile>
LDFLAGS += -L/usr/local/lib -lboost_filesystem
CFLAGS += -pthread -isystem /usr/local/include/boost/ -isystem /usr/local/include


#compiling options
.PHONY:	build clean

build:	$(NAME)

$(NAME): 

clean: 	
	rm -fv *.o $(NAME)