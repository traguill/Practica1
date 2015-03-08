#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <stdio.h>

struct  node{
	int value;
	node* next;
};


class SList{
	node* start;

	unsigned int Count() const{

		node* tmp = start;
		int counter = 0;
		while (tmp != NULL)
		{
			tmp = tmp->next;
			counter++;
		}
		return counter;
	};

	void Add(int valor){

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

	void Delete(int valor){

		node* tmp = start;
		node* beforeTmp;

		while (tmp->value != valor)
		{
			beforeTmp = tmp;
			tmp = tmp->next;
		}
		beforeTmp->next = tmp->next;
		delete[] tmp;
	};
};

#endif