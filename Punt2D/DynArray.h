#ifndef __DYNARRAY_H__
#define __DYNARRAY_H__

#include <stdio.h>

class DynArray{

	private:
		int* data;
		unsigned int allocatedMemory;
		unsigned int numElements;
	public:

		DynArray() :data(NULL), allocatedMemory(0), numElements(0){}
		DynArray(const unsigned memSize){ Reallocate(memSize); }

		~DynArray(){ if (data != NULL) delete[]data; };
		

		void Reallocate(const unsigned int newMemorySize);
		void PushBack(const int value);
		int Pop();
		void Insert(const int value, const unsigned int position);

		int& operator[](const unsigned int index);
		const int& operator[](const unsigned int index) const;

};


#endif