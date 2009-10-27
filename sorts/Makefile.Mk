LANG = c++
.include    <../../Makefile>

#compiling options
.PHONY: all clean

all:  $(NAME)

$(NAME):

clean: nameclean
	rm -fv *.o
	rm -fv *.core