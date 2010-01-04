NAME=ls
LANG = c++
.include	<../Makefile>
LDFLAGS += -lboost_filesystem
CFLAGS += -pthread -isystem /usr/local/include/boost/ -isystem /usr/local/include

#compiling options
.PHONY:	clean

$(NAME): dols.o
dols.o: dols.cpp
dols.cpp: dols.h