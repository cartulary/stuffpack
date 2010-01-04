NAME=ls
LANG = c++
.include	<../Makefile>
LDFLAGS += -lboost_filesystem
CFLAGS += -pthread -isystem /usr/local/include/boost/ -isystem /usr/local/include

#compiling options
.PHONY:	clean

$(NAME): $(NAME).cpp ls_helper.cpp
#$(NAME).o: #dols.o
#ls.o: ls.cpp
#dols.o: dols.cpp
#dols.cpp: dols.h