#ifndef BTREE_H
#define BTREE_H
#include "node.h"
class BinaryTree {
	private:
		unsigned int numnodes;
		MultiNode* head;
		enum { LESS_PTR, MORE_PTR };
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
};
#endif //BTREE_H
