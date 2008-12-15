DIST = text
DISTPATH = text-c
LANG = c
.include <../Makefile.inc>

#compiling options
.PHONY:	build clean forceclean
build:	hanoi.c functions.c
	CC $(CCFLAGS) -o $(NAME).bin hanoi.c
clean: 	
	@echo "cleaning...use make forceclean for unattended clean"
	-rm -irv *.bin
forceclean:
	-rm -rfv *.bin
