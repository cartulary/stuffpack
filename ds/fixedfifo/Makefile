NAME=mall
LANG = c++
USE_CUNIT=yes
USE_NCURSES=yes
.include    <../../Makefile>

#compiling options
.PHONY:     clean

mall: fixedFifo.o dotest.o

fixedFifo.o: boolnode.o fixedFifo.cpp
fixedFifo.cpp: fixedFifo.h

boolnode.o: boolnode.cpp
boolnode.cpp: boolnode.h

dotest.o: dotest.cpp
dotest.cpp: dotest.h