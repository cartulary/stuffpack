CFLAGS := -g -pipe

.ifdef $(LANG) == c++
CC := g++
CFLAGS += -Weffc++
.elif $(LANG) == c
CC := gcc
.endif

CFLAGS += -Wall -Wextra -ansi -pedantic -Wabi
CFLAGS += -Wformat=2 -Wformat-y2k -Wformat-nonliteral -Wformat-security
CFLAGS += -Wctor-dtor-privacy -Wnon-virtual-dtor -Wstrict-null-sentinel -Wswitch-default -Wunused-parameter -Wstrict-null-sentinel -Woverloaded-virtual -Wsign-promo
CFLAGS += -ffor-scope

PREFIX = /usr/local
