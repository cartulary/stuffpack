NAME=ll
LANG=c++
.include	<../../Makefile>

#compiling options
.PHONY:	clean

$(NAME): list.o $(NAME).cpp

list.o: list.h node.o list.cpp
node.o: node.h node.cpp

clean: nameclean coreclean objclean
