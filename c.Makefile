CC := gcc
CCFLAGS := -g -pipe
CCFLAGS += -Wall -Wextra -ansi -pedantic -Wabi
CCFLAGS += -Wformat=2 -Wformat-y2k -Wformat-nonliteral -Wformat-security
CCFLAGS += -Wctor-dtor-privacy -Wnon-virtual-dtor -Wstrict-null-sentinel -Wswitch-default -Wunused-parameter -Wstrict-null-sentinel -Woverloaded-virtual -Wsign-promo
CCGLAGS += -ffor-scope
PREFIX = /usr/local
