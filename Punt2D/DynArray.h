#ifndef __DYNARRAY_H__
#define __DYNARRAY_H__

#include <stdio.h>
#include <assert.h>

template <class Type>
class DynArray{

	private:
		Type* data;
		unsigned int allocatedMemory;
		unsigned int numElements;
	public:

		DynArray() :data(NULL), allocatedMemory(0), numElements(0){}
		DynArray(const unsigned int memSize){ Reallocate(memSize); }

		~DynArray(){ if (data != NULL) delete[]data; };
		
		int getAllocatedMemory()const{
			return allocatedMemory;
		}

		void Reallocate(unsigned int newMemorySize){

			Type* tmp = data;
			allocatedMemory = newMemorySize;
			data = new Type[allocatedMemory];

			if (tmp != NULL)
			{
				for (int i = 0; i < numElements; i++)
				{
					data[i] = tmp[i];
				}
			delete[] tmp;
			}
			 //Maybe we can't delete a null array.
			
		}

		void PushBack(const Type value){
			
			if (allocatedMemory <= numElements) //We don't have extra memory.
			{
				Reallocate(allocatedMemory + 1);
			}
			numElements++;
			data[numElements] = value;
		}

		bool Pop(){
			if (numElements != NULL)
				return data[--numElements];
			else
				return false;
		}

		bool Insert(const Type value, const unsigned int position){
			
			if (position > numElements)
				return false;

			if (position == numElements)
			{
				PushBack(value);
				return true;
			}
			
			if (allocatedMemory <= numElements)
				Reallocate(allocatedMemory + 1);

			for (unsigned int i = numElements; i > position; i--)
			{
				data[i] = data[i - 1];
			}

			data[position] = value;
			numElements++;
			return true;
		}
		

		Type& operator[](const unsigned int index){
			assert(index < numElements);
			
			return data[index];
			
		}
		const Type& operator[](const unsigned int index) const{
			assert(index < numElements);

			return data[index];
		}

	

};


#endif