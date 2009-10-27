DIST = fltk
DISTPATH = fltk
.include    <../Makefile.inc>
CFLAGS = -I/usr/local/include -I/usr/local/include/freetype2 -I/usr/local/include -O2 -fno-strict-aliasing -pipe -I/usr/local/include -Wno-non-virtual-dtor 
LINKCFLAGS += -L/usr/local/lib -lfltk2 -R/usr/local/lib -pthread -lX11 -lXi -lXft -lpthread -lm -lXext -lsupc++ -lstdc++

main: inputWindow.cpp ../hanoi.cpp main.cpp
	$(CC) main.cpp -o $(NAME) $(CFLAGS) $(LINKCFLAGS)

inputWindow.o:
