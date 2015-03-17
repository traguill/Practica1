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
		DynArray(const unsigned int memSize){ Reallocate(memSize); }

		~DynArray(){ if (data != NULL) delete[]data; };
		

		void Reallocate(const unsigned int newMemorySize){
			if (newMemorySize != NULL)
			{
				if (newMemorySize > allocatedMemory || allocatedMemory == NULL)
				{
					allocatedMemory = newMemorySize;
				}
			}
		}
		void PushBack(const int value){
			if (value != NULL)
			{
				if ((numElements + 1) * 4 > allocatedMemory) 
				{
					//We don't have enought memory space so we create more.
					Reallocate((numElements + 1) * 4);
				}
				data[numElements + 1] = value;
			}
		}
		int Pop(){
			if (numElements != NULL)
				return data[numElements - 1];
			else
				return NULL;
		}
		void Insert(const int value, const unsigned int position){
			if (value != NULL)
			{
				if (position < numElements)
				{
					Reallocate(allocatedMemory + 4);
					for (int i = numElements-1; i >= position; i--)
					{	
						data[i + 1] = data[i];
					}
				}
				else
				{
					Reallocate(position * 4);
				}
				data[position] = value;
			}
		}

		int& operator[](const unsigned int index){
			if (index <= numElements - 1){
				return data[index];
			}
		}
		const int& operator[](const unsigned int index) const{
			if (index <= numElements - 1){
				return data[index];
			}
		}

};


#endif