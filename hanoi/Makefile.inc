.include <../../Makefile>

NAME = hanoi
.ifdef $(LANG) == c++
CFLAGS += -fno-threadsafe-statics 
.endif

.PHONY: clean

clean: .NOTMAIN nameclean objclean coreclean 