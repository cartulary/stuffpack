NAME=ds
USE_CUNIT=yes
USE_NCURSES=yes
.include <../Makefile>

FOLDERS=fifo btree

ds: subs ds.cpp

subs:
.for ITEM in $(FOLDERS)
	make -C $(ITEM) mall
.endfor

cleanall:
