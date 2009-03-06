NAME= fortune500
LANG= c
.include <../Makefile>
CFLAGS += -pthread
#replace with a for loop to autoexpand a path?
INCLUDE_PATHS = -I/usr/local/include/gnet -I/usr/local/lib/gnet/include/ -I/usr/local/include/glib12
CFLAGS += $(INCLUDE_PATHS)
CFLAGS += -L/usr/local/lib -lgnet -lgthread-12 -lglib-12 

fortune500:
	$(CC) $(CFLAGS) fortune500.c -o $(NAME)

