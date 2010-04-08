/*
	this class is a pure abstract class that details what functions must be available to ANY
	linked list. *fo, ll, sorted_ll, etc must eventually derive from this base.
*/
class ll_base {
public:
	virtual void clear() = 0;
	virtual ~ll_base() = 0;
};
