NAME=Ttt
LANG=java
.include "../../Makefile"

BuildLoc=java-obj
PackageName=ttt
ClassLoc=$(BuildLoc)/$(PackageName)

CFLAGS += -cp $(BuildLoc)/ -d $(BuildLoc)/

.MAIN: $(NAME).jar
$(NAME).jar: $(ClassLoc)/Ttt.class
	cd $(BuildLoc) && \
	jar vefc $(NAME) ../$(NAME).jar $(NAME).class $(PackageName)/*.class

$(ClassLoc)/Ttt.class: $(ClassLoc)/Game.class Ttt.java
	$(CC) $(CFLAGS) Ttt.java

$(ClassLoc)/Game.class: $(ClassLoc)/TttBoard.class $(ClassLoc)/ButtonPressed.class $(ClassLoc)/AskAgain.class Game.java
	$(CC) $(CFLAGS) Game.java

$(ClassLoc)/TttBoard.class: $(ClassLoc)/Piece.class $(ClassLoc)/ButtonPressed.class TttBoard.java
	$(CC) $(CFLAGS) TttBoard.java

$(ClassLoc)/Piece.class: Piece.java
	$(CC) $(CFLAGS) Piece.java

$(ClassLoc)/AskAgain.class: AskAgain.java
	$(CC) $(CFLAGS) AskAgain.java

$(ClassLoc)/ButtonPressed.class: ButtonPressed.java
	$(CC) $(CFLAGS) $(.ALLSRC)

clean: .PHONY
	rm -rfv $(ClassLoc)/*.class
	rm -rfv $(NAME).jar
