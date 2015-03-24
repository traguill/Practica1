#ifndef __LIST2P_H__
#define __LIST2P_H__

template<class Type>
struct node{
	Type value;
	node<Type>* next;
	node<Type>* prev;
};

template<class Type>
class List2P{

public:
	node<Type>* start;
	node<Type>* end;

private:
	unsigned int size;

public:
		
	//Constructor

	List2P()
	{
		start = end = NULL;
		size = 0;
	}

	//Destructor

	~List2P()
	{
		DeleteAll();
	}

	//Methods

	unsigned int Count()
	{
		return size;
	}

	void Add(const Type data){

		node<Type>* item; 
		item = new node <Type>;
		item->value = data;

		if (start != NULL)
		{
			item->prev = end;
			end->next = item;
			end = item;
			item->next = NULL;
		}
		else
		{
			start = end = item;
			item->prev = item->next = NULL;
		}

		size++;

	}

	bool Delete(node<Type>* item){

		if (item == NULL)
			return false;

		if (item->prev != NULL)
		{
			item->prev->next = item->next;
			if (item->next != NULL)
			{
				item->next->prev = item->prev;
			}
			else
			{
				end = item->prev;
			}

		}
		else
		{
			if (item->next == NULL)
			{
				start = end = NULL;
			}
			else
			{
				start = item->next;
				item->next->prev = NULL;
			}
		}

		delete item;
		size--;
		return true;
	}

	void DeleteAll(){
		node<Type>* tmp;
		node<Type>* tmpNext;

		tmp = start;
		while (tmp != NULL){
			tmpNext = tmp->next;
			delete tmp;
			tmp = tmpNext;
		}

		size = 0;
		start = end = NULL;
	}



};


#endif