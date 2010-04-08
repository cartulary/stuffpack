NAME=ll_base
LANG=c++
.include	<../../Makefile>
CFLAGS += -c 
#compiling options
.PHONY:	clean
mall: $(NAME)
$(NAME): $(NAME).h.ghc
$(NAME).h.ghc:
	$(CC) $(CFLAGS) $(NAME).h|cat