#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <stdio.h>


template <class Type>
struct  node{
	Type value;
	node* next;
};

template <class Type>
class SList{
	node* start;

	unsigned Type Count() const{

		node* tmp = start;
		Type counter = 0;
		while (tmp != NULL)
		{
			tmp = tmp->next;
			counter++;
		}
		return counter;
	};

	void Add(Type valor){

		node* tmp = start;
		if (start != NULL)
		while (tmp->next != NULL){
			tmp = tmp->next;
		}
		node* last = new node;
		last->next = NULL;
		last->value = valor;

		tmp->next = last;

	};

	bool  Delete(node* deletedNode)
	{
		if (deletedNode != NULL && start != NULL)
		{
			if (deletedNode != start)
			{
				node* tmp = start;
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
		node* tmp;
		while (start != NULL)
		{
			tmp = start->next;
			delete start;
			start = tmp;
		}
	}
};

#endif