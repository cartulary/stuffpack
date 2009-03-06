NAME= fortune500
LANG= c
.include <../Makefile>
CFLAGS += -pthread
#replace with a for loop to autoexpand a path?
INCLUDE_PATHS = -I/usr/local/include/gnet -I/usr/local/include/glib12
CFLAGS += $(INCLUDE_PATHS)
CFLAGS += -L/usr/local/lib -lgnet -lgthread-12 -lglib-12 

all: fortune500 client

fortune500.o:
	$(CC) $(CFLAGS) fortune500.c -o $(NAME)
client.o:
	$(CC) $(CFLAGS) fortune500.c -o client

clean:
	rm -rfv ./client ./fortune500

