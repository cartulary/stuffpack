NAME=ls
LANG = c++
.include	<../Makefile>
LDFLAGS += -lboost_filesystem
CFLAGS += -I/usr/local/include/boost/tr1/tr1
CFLAGS += -pthread -isystem /usr/local/include/boost/ -isystem /usr/local/include

#compiling options
.PHONY:	clean

$(NAME): $(NAME).cpp ls_helper.cpp
#$(NAME).o: #dols.o
#ls.o: ls.cpp
#dols.o: dols.cpp
#dols.cpp: dols.h

gfilt: .PHONY
	gfilt -B /usr/local $(NAME).cpp