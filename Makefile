CFLAGS := -g3 -pipe
.ifdef $(LANG) == c++
CC := g++
CFLAGS += -ansi -Wabi
CFLAGS += -Weffc++
CFLAGS += -fno-gnu-keywords
CFLAGS += -Wstrict-null-sentinel -Wctor-dtor-privacy -Wnon-virtual-dtor -Woverloaded-virtual -Wsign-promo
CFLAGS += -ffor-scope
.elif $(LANG) == c
CC := gcc
CFLAGS += -std=c99
CFLAGS += -Wimplicit-function-declaration -Wbad-function-cast -Wdeclaration-after-statement
.endif

CFLAGS += -Wall -Wextra -pedantic
CFLAGS += -Wformat=2 -Wformat-y2k -Wformat-nonliteral -Wformat-security
CFLAGS += -Wunused -Wunused-parameter
CFLAGS += -Winit-self -Wmissing-include-dirs -Wfloat-equal
CFLAGS += -Wfloat-equal -Wundef -Wshadow -Wcast-qual -Wcast-align
CFLAGS += -fabi-version=0 -funroll-loops

PREFIX = /usr/local