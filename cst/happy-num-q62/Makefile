NAME=happy
LANG = c++
USE_HELLO=yes
.include	<../../Makefile>

#compiling options
.PHONY:	clean

$(NAME): $(NAME).o
	$(CC) $(NAME).o -o $(NAME) $(LDFLAGS)
$(NAME).o: