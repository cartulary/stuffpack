#ifndef FIFO_H
#define FIFO_H
#include "node.h"
class Fifo {
	public:
		Node* head;
		Fifo();
		int pop();
		void push(int data);
		//void printAll();
};
#endif
