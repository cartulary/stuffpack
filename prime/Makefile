NAME=primeA
LANG = c++
USE_HELLO=yes
.include	<../Makefile>

.PHONY:	clean

primeA: primeA.o
	$(CC) -o $(NAME) $(NAME).o $(LDFLAGS)

primeA.o: primeA.cpp 

clean: nameclean objclean coreclean