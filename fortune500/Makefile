NAME= fortune500
LANG= c
.include <../Makefile>
CFLAGS += -pthread
#replace with a for loop to autoexpand a path?
INCLUDE_PATHS = -I/usr/local/include/gnet -I/usr/local/include/glib12
CFLAGS += $(INCLUDE_PATHS)
LDFLAGS += -lgnet -lgthread-12 -lglib-12 
LINT_FLAGS= -H -aa -bcehprsx $(INCLUDE_PATHS)

all: fortune500 client

fortune500.o:
	$(CC) $(CFLAGS) fortune500.c -o $(NAME)
client.o:
	$(CC) $(CFLAGS) fortune500.c -o client

clean:
	rm -rfv ./client ./fortune500

lint:
	lint $(LINT_FLAGS) client.c|grep client.c
	lint $(LINT_FLAGS) fortune500.c|grep fortune500.c