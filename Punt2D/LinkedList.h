#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <stdio.h>

struct  node{
	int value;
	node* next;
};


class SList{
	node* start;

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
};

#endif