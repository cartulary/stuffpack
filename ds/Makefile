NAME=ds
USE_CUNIT=yes
USE_NCURSES=yes
.include <../Makefile>
FOLDERS=node fifo btree
ds: subs ds.cpp
subs:
.for FOLDER in $(FOLDERS)
	make -C $(FOLDER) mall
.endfor
cleanall:
.for FOLDER in $(FOLDERS)
	make -C $(FOLDER) clean
.endfor
