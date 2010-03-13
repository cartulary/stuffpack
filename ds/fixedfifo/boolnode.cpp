#include "boolnode.h"

template <class T>
BoolNode<T>::BoolNode(): active(false), data(0)
{
}

template <class T>
void BoolNode<T>::setValue(dataType d)
{
	this->active = true;
	this->data = d;
}

template <class T>
void BoolNode<T>::deactivate()
{
	this->active = false;
}

template <class T>
T BoolNode<T>::getValue()
{
	return this->data;
}

template <class T>
bool BoolNode<T>::isActive()
{
	return this->active;
}
