LANG = c++
.include    <../../Makefile>

#compiling options
.PHONY: all clean

all:  $(NAME)

$(NAME):

clean:
	rm -fv *.o
	rm -fv ./${NAME} *.core