#ifndef BTREE_H
#define BTREE_H
#include "node.h"
#include "../fifo/DuplicateEntry.h"
#include "DataNotExistException.h"

#define BTREE_TEMPLATE template <class T>
template <class T>
class BinaryTree {
	private:
		unsigned int numnodes;
		MultiNode<T>* head;
		enum { LESS_PTR, MORE_PTR};
		void debugPrintTree_helper(MultiNode<T>* ptr, int tabs);
		void clear_helper(MultiNode<T>* ptr);
	protected:
		// this is special type of add for "re-adding" a node. It is used by the
		// remove function to avoid repeating functionality
		void add(MultiNode<T>* data);
	public:
		BinaryTree();
		//~BinaryTree();

		/* functions for adding, removing, or determining if data exists */
		void add(T data);
		void remove(T data);
		bool has(T data);

		/* Remove all nodes */
		void clear();

		/* Return the number of active nodes */
		unsigned int getNumNodes();

		/* prints out the tree for debugging reasons */
		void debugPrintTree();
};
#endif //BTREE_H
