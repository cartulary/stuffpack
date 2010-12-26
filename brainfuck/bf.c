/*
	A naive and quick implementation of brainfuck
	Eitan Adler
*/
#include <stdio.h>
#include <stdlib.h>
#define PROGSIZE 4096
int main(void) {
	int matchcount;
	//Start off with a small stack and grow
	unsigned int stacksize = 25;
	int *stack = calloc(stacksize,sizeof(int));
	char program[PROGSIZE] = { 0 };
	fgets(program,PROGSIZE, stdin);
	unsigned int sp = 0;
	unsigned int ip = 0;

	while (program[ip] != 0) {
		switch ((int)program[ip]) {
			case '>':
				++sp;
			break;
			case '<':
				--sp;
			break;
			case '+':
				++(stack[sp]);
			break;
			case '-':
				--(stack[sp]);
			break;
			case '.':
				printf("%c",stack[sp]);
			break;
			case ',':
				scanf("%c",stack[sp]);
			break;
			case '[':
				matchcount = 1;
				if (stack[sp] == 0){
					while (matchcount != 0) {
						++ip;
						if (program[ip] == '['){
							matchcount++;
						}
						else if (program[ip] == ']') {
							matchcount--;
						}
					}
				}
			break;
			case ']':
				matchcount = 1;
				if (stack[sp] != 0){
					while (matchcount != 0) {
						--ip;
						if (program[ip] == ']'){
							matchcount++;
						}
						else if (program[ip] == '[') {
							matchcount--;
						}
					}
				}
			break;
		}
		if (sp > stacksize) {
			const unsigned int oldsize = stacksize;
			stacksize *= 1.5;
			realloc(stack, stacksize);
			for (unsigned int i = oldsize; i < stacksize; ++i)	{
				stack[i] = 0;
			}
		}
		++ip;
	}
	return 0;
}
