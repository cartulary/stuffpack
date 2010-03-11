NAME=ds
USE_CUNIT=yes
USE_NCURSES=yes
.include <../Makefile>
FOLDERS=fifo btree
ds: subs ds.cpp
subs:
	make -C fifo mall
	make -C btree mall
cleanall:
	make -C fifo clean
	make -C btree clean