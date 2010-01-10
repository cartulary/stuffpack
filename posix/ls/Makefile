NAME=ls
LANG = c++
.include	<../Makefile>
LDFLAGS += -lboost_filesystem
CFLAGS += -I/usr/local/include/boost/tr1/tr1
CFLAGS += -pthread -isystem /usr/local/include/boost/ -isystem /usr/local/include

#compiling options
.PHONY:	clean

#$(NAME): ls.cpp ls_helper.cpp
$(NAME): dols.o ls.cpp
ls.cpp: ls_helper.cpp
dols.o: dols.h dols.cpp

gfilt: .PHONY
	gfilt -B /usr/local $(NAME).cpp