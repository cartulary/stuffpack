#include "fixedFifo.h"
#include "boolnode.h"
#include "../fifo/OutOfBoundsException.h"
#include <iostream>
#include <err.h>

FixedFifo::FixedFifo(unsigned int m): head(0), tail(0), max(m), numNodes(0)
{
	vals = new BoolNode<int>[m];
}

FixedFifo::~FixedFifo()
{
	delete[] vals;
}

void FixedFifo::push(BoolNode<int>::dataType d)
{
	if (!vals[head].isActive())
	{
		++numNodes;
		vals[head].setValue(d);
		head = (head++) % this->max;
		return;
	}
	else
	{
		//throw exception - tooMuchData
		throw OutOfBoundsException();
		return;
	}
}
bool FixedFifo::hasNext()
{
	return vals[tail].isActive();
}

int FixedFifo::pop()
{
	if (vals[tail].isActive())
	{
		//std::cout << "New tail for:" << (tail+1)%this->tail << "\n";
		//errx(0,"leave");
		//return 0;
		int ret = vals[tail].getValue();
		vals[tail].deactivate();
		tail = (tail++) % this->max;
		--numNodes;
		return ret;
	}
	else
	{
		//throw exception - bad pop
		return 0;
	}
}

void FixedFifo::clear()
{
	unsigned int i;
	for (i=0; i < max; ++i)
	{
		if (vals[i].isActive())
		{
			vals[i].deactivate();
			//delete vals[i];
		}
	}
	head = tail = 0;
}

void FixedFifo::print()
{
	std::cout << "\n";
	unsigned int i;
	for (i=0; i < max; ++i)
	{
		if (vals[i].isActive())
		{
			std::cout << vals[i].getValue();
		}
		else
		{
			std::cout << "-";
		}
		std::cout << " ";
	}
	std::cout << "\nhead (" << head <<") tail (" << tail << ") with " << numNodes << " nodes\n";
}

int FixedFifo::getNumNodes()
{
	return this->numNodes;
}
