#include "list.h"
#include <cstddef>

list::list()
{
	this->next=NULL;
	prev=NULL;
	data=0;
//	return NULL;
}

list::add()
{
	this->next=new list();
}