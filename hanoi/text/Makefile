DIST = text
DISTPATH = text
LANG = c++
.include	<../Makefile.inc>
#compiling options
.PHONY:	build clean forceclean
build:	../hanoi.cpp main.cpp functions.cpp
	CC $(CCFLAGS) -o $(NAME).bin main.cpp
clean: 	
	@echo "cleaning...use make forceclean for unattended clean"
	-rm -irv *.bin
forceclean:
	-rm -rfv *.bin
