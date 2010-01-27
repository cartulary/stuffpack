#ifndef FO_H
#define FO_H
#include "node.h"
#include <vector>
template <class T> class Fo {
	private:
		int numnodes;
	protected:
		std::vector<T> getAll();
		//Because pop_helper is implemented by the derived classes
		//pop contains the common code
		virtual T pop_helper() = 0;
	public:
		Node<T>* head;
		Fo();
		virtual ~Fo();
		Fo (const Fo<int>& newfo);
		bool operator==(const Fo<T>& other) const;
		bool operator!=(const Fo<T>& other) const;
		//bool operator
		//must override = and copy

		T pop();
		virtual Node<T>* getNextNode(int fastfoward=0) = 0;

		void push(T data);
		inline bool hasNext();
		virtual void printAll(bool doPop=false) =0;
		int getNumNodes();
		//clear function - erases all data
};
#endif
