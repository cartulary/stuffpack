NAME = hanoi
.include "../Makefile"

.ifdef $(LANG) == c++
CFLAGS += -fno-threadsafe-statics 
.endif

.PHONY: clean

$(NAME): main
