#include "node.cpp"
class Fifo {
	public:
		Node* head;
		Fifo();
		int pop();
		void push(int data);
		//void printAll();
};
