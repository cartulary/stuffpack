class list
{
	public:
		/* link to next item in chain */
		list* next;
		/* link to prev item in chain */
		list* prev;

		/* first item in chain - useful? */
		static list* head;

		/* well - the most important part*/
		int data;

		/* adds item right after this node?? */
		list* add();
		/* removes this node */
		list* rm();

		/* constructor */
		list();

};
