#ifndef __DYNARRAY_H__
#define __DYNARRAY_H__

#include <stdio.h>
#include <assert.h>

class DynArray{

	private:
		int* data;
		unsigned int allocatedMemory;
		unsigned int numElements;
	public:

		DynArray() :data(NULL), allocatedMemory(0), numElements(0){}
		DynArray(const unsigned int memSize){ Reallocate(memSize); }

		~DynArray(){ if (data != NULL) delete[]data; };
		
		const int getAllocatedMemory()const{
			return allocatedMemory;
		}

		void Reallocate(const unsigned int newMemorySize){

			if (data != NULL)
			{
				int*tmp = new int[allocatedMemory];
				CopyArray(tmp, data, allocatedMemory);
				delete[] data;

				data = new int[newMemorySize];
				CopyArray(data, tmp, allocatedMemory);

				allocatedMemory = newMemorySize;
				delete[] tmp;
			}
			else
			{
				data = new int[newMemorySize];
				allocatedMemory = newMemorySize;
			}
		}

		void PushBack(const int value){
			if (value != NULL)
			{
				if ((numElements + 1) > allocatedMemory) 
				{
					//We don't have enought memory space so we create more.
					Reallocate((numElements + 1));
				}
				data[numElements] = value;
				numElements++;
				allocatedMemory++;
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
			assert(index < numElements);
			
			return data[index];
			
		}
		const int& operator[](const unsigned int index) const{
			assert(index < numElements);

			return data[index];
		}

	private:
		
		void CopyArray(int* destination, int* source, int memory){
			for (int i = 0; i < memory; i++)
			{
				destination[i] = source[i];
			}
		}

};


#endif