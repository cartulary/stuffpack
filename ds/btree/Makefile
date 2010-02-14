NAME=mall
LANG = c++
USE_CUNIT=yes
USE_NCURSES=yes
.include    <../../Makefile>

#compiling options
.PHONY:     clean

mall: btree.o dotest.o

btree.o: require_node btree.cpp
btree.cpp: btree.h

dotest.o: dotest.cpp
dotest.cpp: dotest.h

require_node: .PHONY
	make -C ../node mall