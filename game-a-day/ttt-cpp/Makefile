NAME=ttt
LANG=c++
USE_FLTK=yes
COMPILER=gcc
.include	<../../Makefile>
CFLAGS += -I/usr/local/include/FL/images -I/usr/local/include/freetype2 -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_THREAD_SAFE -D_REENTRANT 
LDFLAGS += -lfltk -lX11 -lXi -lXinerama -lXcursor -lXft -lm -lXext -lsupc++ 

$(NAME): $(NAME).o
	$(CC) $(CFLAGS) $(NAME).cpp board.o piece.o $(LDFLAGS) -o $(NAME)

$(NAME).o: board.o $(NAME).cpp

board.o: piece.o board.cpp
board.cpp: board.h
piece.o: piece.cpp
piece.cpp: piece.h

