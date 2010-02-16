#ifndef BTREE_H
#define BTREE_H
#include "node.h"
#include "../fifo/DuplicateEntry.h"
class BinaryTree {
	private:
		unsigned int numnodes;
		MultiNode<int>* head;
		enum { LESS_PTR, MORE_PTR};
		void debugPrintTree_helper(MultiNode<int>* ptr, int tabs);
		void clear_helper(MultiNode<int>* ptr);
	protected:
		// this is special type of add for "re-adding" a node. It is used by the
		// remove function to avoid repeating functionality
		void add(MultiNode<int>* data);
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
