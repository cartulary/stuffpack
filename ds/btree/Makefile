NAME=main
LANG = c++
USE_CUNIT=yes
USE_NCURSES=yes
.include    <../../Makefile>

#compiling options
.PHONY:     clean

mall: btree.o dotest.o

btree.o: node.o btree.cpp
btree.cpp: btree.h

node.o: node.cpp
node.cpp: node.h

dotest.o: dotest.cpp
dotest.cpp: dotest.h