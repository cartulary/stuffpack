NAME=mall
LANG = c++
USE_CUNIT=yes
USE_NCURSES=yes
.include    <../../Makefile>

#compiling options
.PHONY:     clean

mall: ll.o lifo.o sorted.o fifo.o ll_it.o dotest.o main_ll_it
main_ll_it: ll_it.o main_ll_it.cpp

fifo.o: node.o fo.o printit.o fifo.cpp 
fifo.cpp: fifo.h

lifo.o: node.o fo.o printit.o lifo.cpp 
lifo.cpp: lifo.h

fo.o: node.o fo.cpp
fo.cpp: fo.h

node.o: node.cpp
node.cpp: node.h

printit.o: printit.cpp
printit.cpp: printit.h

ll.o:  OutOfBoundsException.o ll.cpp
ll.cpp: ll.h

dotest.o: fifo.o lifo.o ll.o dotest.cpp
dotest.cpp: dotest.h

OutOfBoundsException.o:  OutOfBoundsException.cpp
OutOfBoundsException.cpp:  OutOfBoundsException.h

sorted.o: fifo.o sorted.cpp
sorted.cpp: sorted.h

ll_it.o: ll_it.cpp
ll_it.cpp: ll_it.h