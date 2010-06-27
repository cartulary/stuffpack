NAME=ds
USE_CUNIT=yes
USE_NCURSES=yes
USE_GFILT=yes
LANG=c++
.include <../Makefile>

#-depth is an extension - perhaps use -mindepth and -maxdepth instead?
FOLDERS != find . \! -iname ".*" -type d -depth 1 -exec basename {} \;

ds: subs ds.cpp

subs: .MAKE fifo/fifo.o fifo/lifo.o fifo/sorted.o btree/btree.o fifo/dotest.o btree/dotest.o graph/dotest.o graph/graph.o
.for ITEM in $(FOLDERS)
	make -C $(ITEM) mall
.endfor

cleanall: coreclean objclean nameclean
.for ITEM in $(FOLDERS)
	make -C $(ITEM) clean
.endfor
