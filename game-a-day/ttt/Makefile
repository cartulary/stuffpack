NAME=Ttt
LANG=java
.include	<../../Makefile>

CFLAGS +=  -cp ttt/ -d ttt/
$(NAME): Piece TttBoard $(NAME).java
	$(CC) $(CFLAGS) $(SRCFILE)
TttBoard: TttBoard.java Piece
	$(CC) $(CFLAGS) TttBoard.java
Piece: Piece.java
	$(CC) $(CFLAGS) Piece.java

