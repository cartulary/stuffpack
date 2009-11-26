NAME=primeA
LANG = c++
USE_HELLO=yes
.include	<../Makefile>

.PHONY:	clean

primeA: primeA.o
	$(CC) $(.ALLSRC) -o $(NAME) $(LDFLAGS)

$(OBJS): $(.PREFIX).cpp
