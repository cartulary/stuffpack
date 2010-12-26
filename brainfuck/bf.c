/*
	A naive and quick implementation of brainfuck
	Eitan Adler
*/
#include <stdio.h>
#include <stdlib.h>
#define STACKSIZE 256
#define PROGSIZE 4096
int main(void) {
	int matchcount;
	int stack[STACKSIZE] = { 0 };
	char program[PROGSIZE] = { 0 };
	fgets(program,PROGSIZE, stdin);
	int sp = 0;
	int ip = 0;

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
		++ip;
	}
	return 0;
}
