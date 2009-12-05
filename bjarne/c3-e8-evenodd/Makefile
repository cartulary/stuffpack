NAME=evenodd
LANG=c++
USE_HELLO=yes
.include	<../../Makefile>

#compiling options
.PHONY:	clean

$(NAME): $(NAME).o
	$(CC) -o $(NAME) $(.ALLSRC) $(LDFLAGS)
$(NAME).o:
