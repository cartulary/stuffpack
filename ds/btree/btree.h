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
		/* specifically define 0 and 1 to allow for !childType to refer to the the other one - even if we keep track of our parents */
		enum childType { LESS_PTR=0, MORE_PTR=1 };
		void debugPrintTree_helper(MultiNode<T>* ptr, unsigned int tabs) const;
		void clear_helper(MultiNode<T>* ptr);
	protected:
		// this is special type of add for "re-adding" a node. It is used by the
		// remove function to avoid repeating functionality
		inline void add(MultiNode<T>* data);
		/* Add data at a particular place - used by remove... */
		void addAt(MultiNode<T>* ptr, MultiNode<T>* &loc);
	public:
		BinaryTree();
		//~BinaryTree();

		/* functions for adding, removing, or determining if data exists */
		void add(T data);
		void remove(T data);
		bool has(T data) const;

		/* Remove all nodes */
		void clear();

		/* Return the number of active nodes */
		unsigned int getNumNodes() const;

		/* prints out the tree for debugging reasons */
		void debugPrintTree() const;
};
#endif //BTREE_H
