#include "fixedFifo.h"
#include "boolnode.h"

FixedFifo::FixedFifo(unsigned int m): head(0), tail(0), max(m)
{
	vals = new BoolNode<int>[m];
	location i=0;
	BoolNode<int>::dataType x = 0;
	for(; i < m; ++i)
	{
		vals[i].setValue(x);
	}
}

FixedFifo::~FixedFifo()
{
	delete[] vals;
}

void FixedFifo::push(BoolNode<int>::dataType d)
{
	if (!vals[head].isActive())
	{
		vals[head].setValue(d);
	}
	else
	{
		//throw exception - tooMuchData
		return;
	}
	head = (head++) % this->max;
}
bool FixedFifo::hasNext()
{
	return true;
}

int FixedFifo::pop()
{
	return 0;
}
