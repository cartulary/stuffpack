NAME=primeA
LANG = c++
USE_HELLO=yes
.include	<../Makefile>
BINNAME=$(NAME)-bin

.PHONY:	clean

$(NAME): $(NAME).o
	$(CC) $(.ALLSRC) -o $(BINNAME) $(LDFLAGS)
	@echo "#!/usr/bin/env sh" > $(NAME);
	@echo "LD_LIBRARY_PATH='../libhello/' ./$(BINNAME)" >> $(NAME);
	@chmod +x $(NAME)

$(OBJS): $(.PREFIX).cpp

clean: nameclean coreclean objclean
	rm -f $(BINNAME)