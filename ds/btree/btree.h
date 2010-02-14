#ifndef BTREE_H
#define BTREE_H
#include "node.h"
class BinaryTree {
	private:
		unsigned int numnodes;
		MultiNode<int>* head;
		enum { LESS_PTR, MORE_PTR, PARENT_PTR };
		void debugPrintTree_helper(MultiNode<int>* ptr, int tabs);
		void clear_helper(MultiNode<int>* ptr);
	public:
		BinaryTree();
		//~BinaryTree();

		/* functions for adding, removing, or determining if data exists */
		void add(int data);
		void remove(int data);
		bool has(int data);

		/* Remove all nodes */
		void clear();

		/* Return the number of active nodes */
		unsigned int getNumNodes();

		/* prints out the tree for debugging reasons */
		void debugPrintTree();
};
#endif //BTREE_H
