#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <stdio.h>


template <class Type>
struct  node{
	Type value;
	node<Type>* next;
};

template <class Type>
class SList{
	node<Type>* start;

	unsigned Type Count() const{

		node<Type>* tmp = start;
		Type counter = 0;
		while (tmp != NULL)
		{
			tmp = tmp->next;
			counter++;
		}
		return counter;
	};

	void Add(Type valor){

		node<Type>* tmp = start;
		if (start != NULL)
		while (tmp->next != NULL){
			tmp = tmp->next;
		}
		node<Type>* last = new node;
		last->next = NULL;
		last->value = valor;

		tmp->next = last;

	};

	bool  Delete(node<Type>* deletedNode)
	{
		if (deletedNode != NULL && start != NULL)
		{
			if (deletedNode != start)
			{
				node<Type>* tmp = start;
				while (tmp && tmp->next != deletedNode)
				{
					tmp = tmp->next;
				}
				if (tmp)
				{
					tmp->next = deletedNode->next;
				}
				else
				{
					return false;
				}
			}
			else
			{
				start = start->next;
			}
			delete deletedNode;
			return true;
		}
		return false;
	};

	void  DeleteAll()
	{
		node<Type>* tmp;
		while (start != NULL)
		{
			tmp = start->next;
			delete start;
			start = tmp;
		}
	}
};

#endif