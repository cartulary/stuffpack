DIST = trunk
DISTPATH = trunk/
LANG=c++
.include <../../Makefile>

#compiling options
.PHONY:	build clean forceclean
build:	ttt.cpp
	CC $(CFLAGS) -o $(NAME).bin ttt.cpp
clean: 	
	@echo "cleaning...use make forceclean for unattended clean"
	-rm -irv *.bin
forceclean:
	-rm -rfv *.bin
