NAME=libhello
LANG=c++
.include <../Makefile>

.ifdef $(.TARGETS) == shared
CFLAGS += -fPIC
.endif


static: $(NAME).o $(NAME).a

shared: $(NAME).o $(NAME).so.0.0
	ln -sf libhello.so.0.0 libhello.so.0
	ln -sf libhello.so.0 libhello.so

$(NAME).so.0.0:
	g++ -shared -Wl,-soname,$(NAME).so.0 -o $(NAME).so.0.0 $(NAME).o 

$(NAME).a:
	ar rcs $(NAME).a $(NAME).o

$(NAME).o:
	g++ $(CFLAGS) -c $(NAME).cpp

$(NAME).a: $(NAME).o
	
postclean:
	rm -f *.o
clean:
	rm -f *.o *.a
	rm -f *.so*

