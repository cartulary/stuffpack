#ifndef NODE_H
#define NODE_H
template <class T> class Node {
	public:
		Node(T data);
		T data;
		Node<T>* next;
};
#endif
