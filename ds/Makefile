NAME=ds
USE_CUNIT=yes
USE_NCURSES=yes
.include <../Makefile>

FOLDERS=fifo btree

ds: subs ds.cpp

subs: .MAKE fifo/fifo.o fifo/lifo.o fifo/sorted.o btree/btree.o fifo/dotest.o btree/dotest.o
.for ITEM in $(FOLDERS)
	make -C $(ITEM) mall
.endfor

cleanall: coreclean objclean nameclean
.for ITEM in $(FOLDERS)
	make -C $(ITEM) clean
.endfor
