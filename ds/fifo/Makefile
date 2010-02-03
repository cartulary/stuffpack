NAME=fifo
LANG = c++
USE_CUNIT=yes
USE_NCURSES=yes
.include    <../Makefile>

#compiling options
.PHONY:     clean

fifo.o: node.o fo.o printit.o fifo.cpp 
fifo.cpp: fifo.h

lifo.o: node.o fo.o printit.o lifo.cpp 
lifo.cpp: lifo.h

fo.o: node.o fo.cpp
fo.cpp: fo.h

node.o: node.cpp
node.cpp: node.h

ll.o:  OutOfBoundsException.o ll.cpp
ll.cpp: ll.h

OutOfBoundsException.o:  OutOfBoundsException.cpp
OutOfBoundsException.cpp:  OutOfBoundsException.h
clean: objclean