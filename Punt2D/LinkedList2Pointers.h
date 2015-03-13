#ifndef __LINKEDLIST2POINTERS_H__
#define __LINKEDLIST2POINTERS_H__

#include <stdio.h>


template <class Type>
struct  node{
	Type value;
	node* next;
	node* before;
};

template <class Type>
class SList2Pointers{
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
		node* last = new node;

		if (start != NULL)
		{
			while (tmp->next != NULL){
				tmp = tmp->next;
			}
			last->before = tmp;
		}
		else
		{
			last->before = NULL;
		}

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
					if (tmp == NULL)
						return false;
				}
				tmp->next = deletedNode->next;
				node* tmp2 = deletedNode->next;
				tmp2->before = tmp;
				
			}
			else
			{
				node* tmp = start->next;
				start = tmp;
				tmp->before = NULL;
			}
			delete deletedNode;
			return true;
		}
		else{
			return false;
		}
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