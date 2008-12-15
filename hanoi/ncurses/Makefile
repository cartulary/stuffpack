DIST = ncurses
DISTPATH = ncurses
LANG = c++
.include <../Makefile.inc>
CCFLAGS += -lncurses

#compiling options
.PHONY:	build clean forceclean
build:	hanoi.cpp functions.cpp
	CC $(CCFLAGS) -o $(NAME).bin hanoi.cpp
clean: 	
	@echo "cleaning...use make forceclean for unattended clean"
	-rm -irv *.bin
forceclean:
	-rm -rfv *.bin
