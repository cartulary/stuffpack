#ifndef NODE_H
#define NODE_H
class Node {
	public:
		Node(int data);
		int data;
		Node* next;
		Node* prev;
};
#endif
