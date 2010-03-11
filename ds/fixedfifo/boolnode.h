#ifndef BOOLNODE_H
#define BOOLNODE_H
template <class T>
class BoolNode {
	public:
		typedef T dataType;
		void setValue(dataType data);
		void deactivate();
		bool isActive();
		T getValue();
		BoolNode();
	private:
		bool active;
		dataType data;
};
#endif
