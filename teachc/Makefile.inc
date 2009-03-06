.include <../../Makefile>

NAME = teachc
.ifdef $(LANG) == c++
CFLAGS += -fno-threadsafe-statics 
.endif
