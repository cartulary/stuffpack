NAME=prime
LANG = c++
USE_HELLO=yes
.include	<../../Makefile>

#compiling options
.PHONY:	clean

$(NAME): $(NAME).o
	$(CC) -o $(NAME) $(NAME).o $(LDFLAGS)

$(NAME).o:

clean: nameclean objclean coreclean
