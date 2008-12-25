CFLAGS := -g -pipe
.ifdef $(LANG) == c++
CC := g++
CFLAGS += -ansi
CFLAGS += -Weffc++
.elif $(LANG) == c
CC := gcc
CFLAGS += -std=c99
CFLAGS += -Wimplicit-function-declaration -Wbad-function-cast -Wdeclaration-after-statement
.endif

CFLAGS += -Wall -Wextra -pedantic -Wabi
CFLAGS += -Wformat=2 -Wformat-y2k -Wformat-nonliteral -Wformat-security
CFLAGS += -Wunused -Wunused-parameter -Wunknown-pragmas
CFLAGS += -Wctor-dtor-privacy -Wnon-virtual-dtor -Wstrict-null-sentinel -Wstrict-null-sentinel -Woverloaded-virtual -Wsign-promo
CFLAGS += -Winit-self -Wmissing-include-dirs -Wfloat-equal
CFLAGS += -Wfloat-equal -Wundef -Wshadow -Wcast-qual -Wcast-align
CFLAGS += -ffor-scope -funroll-loops

PREFIX = /usr/local


### update to c99 standard eventually ??? ###