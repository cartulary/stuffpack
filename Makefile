NAME=hello
LANG = c++
.include    <../Makefile>
CFLAGS = -I/usr/local/include -I/usr/local/include/freetype2 -I/usr/local/include -O2 -fno-strict-aliasing -pipe -I/usr/local/include -Wno-non-virtual-dtor -L/usr/local/lib -lfltk2 -R/usr/local/lib -pthread -lX11 -lXi -lXft -lpthread -lm -lXext -lsupc++

#compiling options
.PHONY:     clean

all:  $(NAME)

$(NAME):
	$(CC) $(NAME).cpp -o $(NAME) $(CFLAGS)

clean:
	rm -fv *.o
	rm ./$(NAME)