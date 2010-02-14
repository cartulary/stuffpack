#include "sorted.h"
#include "DuplicateEntry.h"
#include <iostream>
/*      Perhaps we could get get this to either work with lifo OR fifo at runtime??
*/
template <class T> void Sorted<T>::push(T data)
{
    ++(this->numnodes);
    Node<T>* current = this->head;
    if (!current)
    {
        this->head = new Node<T>(data);
        return;
    }
        /* if we are stuck in the first position */
        if (data < current->data)
        {
                this->head = new Node<T>(data);
                this->head->next=current;
                return;
        }
        else if (data == current->data)
        {
                throw DuplicateEntryException();
        }

        while (current->next)
        {
                if (data < current->next->data)
                {
                        break;
                }
                else if (data == current->next->data)
                {
                        throw DuplicateEntryException();
                }
                current=current->next;
        }
        Node<T>* tmp = current->next;
    current->next = new Node<T>(data);
        current->next->next = tmp;
}
