// Standard IO libraries for C
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*   My Text Adventure Game
*	| Troll | Troll | Troll |
*	| Troll | Frog  | Troll |
*	| Troll | Troll | Troll |
*
*	Str & Health
*	Killing monster inc. str
*	Monster hits you dec. health
*	Killing monster drops possible item
*	items: potion (inc health)
*		sword   (inc str)
*		charm (inc luck)
*		key (gets you to the frog)
*	limitation = every room/monster can carry only ONE item
*
*/
enum itemType {
	ITEM_NONE,
	SWORD,
	CHARM,
	POTION,
	KEY
};

struct item {
	enum itemType type;
};

enum monsterType {
	MONSTER_NONE,
	TROLL,
	FROG
};

struct monster {
	const char * name;
	unsigned int life;
	unsigned int str;
	struct item* carrying;
	enum monsterType type;
};

struct room {
	const char * descr;
	struct item treasure;
	struct monster m;
};

enum action {
	GO_NORTH,
	GO_SOUTH,
	GO_EAST,
	GO_WEST,
	OPEN_LOCK,
	ATTACK,
	QUIT
};

const int bufSize = 10;

enum action promptNextAction() {
	char buf[bufSize];
	while (true) {
		fgets(buf, bufSize - 1, stdin);
		if (strcmp("n\n",buf) == 0) {
			return GO_NORTH;
		}
		else if (strcmp("s\n",buf) == 0) {
			return GO_SOUTH;
		}
		else if (strcmp("e\n",buf) == 0) {
			return GO_EAST;
		}
		else if (strcmp("w\n",buf) == 0) {
			return GO_WEST;
		}
		else if (strcmp("open\n",buf) == 0) {
			return OPEN_LOCK;
		}
		else if (strcmp("attack\n",buf) == 0) {
			return ATTACK;
		}
		else if (strcmp("quit\n",buf) == 0) {
			return QUIT;
		}
	}
}

void drawScreen(struct room const * const * const rooms, const unsigned int cols, const unsigned int rows) {
	unsigned int c;
	unsigned int r;
	for (c = 0; c < cols; ++c) {
		for (r = 0; c < rows; ++r) {
			if (rooms[c][r].m.type != NONE ) {
				printf("X");
			}
		}
	}
}

const int nCols = 3;
const int nRows = 3;
// Main routine.  Print hello, give instructions, ...
int main()
{
	struct room roomList[nCols][nRows];
	unsigned int curCol = 0;
	unsigned int curRow = 1;
	enum action a;
	while ((a = promptNextAction()) != QUIT)
	{
	}
	return 0;
}
