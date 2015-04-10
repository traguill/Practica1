#ifndef __TREEG__H_
#define __TREEG__H_

#include "List2P.h"

template <class Type>
struct nodeT{
	Type data;
	nodeT<Type>* dad;
	List2P<Type> son;
};


template <class Type>
class TreeG{
public:
	nodeT<Type>* rootNode;

	TreeG(){ rootNode = NULL; }

	void Add(const Type data, nodeT<Type>* father){
		nodeT<Type>*item = new nodeT<Type>;
		if (father)
		{
			item->dad = father;
		}
		else
		{
			rootNode = item;
			item->dad = NULL;
		}
		item->data = data;
		item->son = NULL;

		father->son.Add(item);
	}

};


#endif // !__TREEG__H_

