NAME = hanoi
CC := g++
CCFLAGS := -g -pipe
CCFLAGS += -Wall -Wextra -ansi -pedantic -Weffc++ -Wabi
CCFLAGS += -Wformat=2 -Wformat-y2k -Wformat-nonliteral -Wformat-security
CCFLAGS += -Wctor-dtor-privacy -Wnon-virtual-dtor -Wstrict-null-sentinel -Wswitch-default -Wunused-parameter -Wstrict-null-sentinel -Woverloaded-virtual -Wsign-promo
CCGLAGS += -ffor-scope
CCFLAGS += -lform -lncurses
PREFIX = /usr/local

#compiling options
.PHONY:	build clean forceclean
build:	hanoi.cpp functions.cpp
	CC $(CCFLAGS) -o $(NAME).bin hanoi.cpp 	
clean: 	
	@echo "cleaning...use make forceclean for unattended clean"
	-rm -irv *.bin
forceclean:
	-rm -rfv *.bin
