#ifndef BTREE_H
#define BTREE_H
class BinaryTree {
	private:
		unsigned int numNodes;
	public:
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
