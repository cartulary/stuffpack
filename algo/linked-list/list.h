#include "node.h"

class list
{
	public:
		/* first item in chain - useful? */
		node* head;

		/* adds item right after this node?? */
		node* add(int data);
		/* removes this node */
		node* rm();

		/* constructor */
		list();

		node nodes[5];
};
