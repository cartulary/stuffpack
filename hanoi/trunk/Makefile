DIST = trunk
DISTPATH = trunk
LANG = c
.include <../Makefile>
CCFLAGS += -lncurses

#compiling options
.PHONY:	build clean forceclean
build:	hanoi.c 
	CC $(CCFLAGS) -o $(NAME).bin hanoi.c
hanoi.c: functions.o functions.h
functionc.c: functions.h
clean: 	
	@echo "cleaning...use make forceclean for unattended clean"
	-rm -irv *.bin
forceclean:
	-rm -rfv *.bin
