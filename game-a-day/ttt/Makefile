NAME=Ttt
LANG=java
.include	<../../Makefile>

#compiling options
.PHONY:	clean

CFLAGS +=  -cp ttt/ -d ttt/
$(NAME): Piece TttBoard $(NAME).java
	export CLASSPATH=".;ttt/"
	$(CC) $(CFLAGS) $(SRCFILE)
TttBoard: TttBoard.java Piece
	$(CC) $(CFLAGS) TttBoard.java
Piece: Piece.java
	$(CC) $(CFLAGS) Piece.java


clean: javaclean
