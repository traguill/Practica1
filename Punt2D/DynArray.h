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
			if (data != NULL)
			{
				if ((numElements + 1) > allocatedMemory) 
				{
					//We don't have enought memory space so we create more.
					Reallocate((numElements + 1));
				}
				data[numElements] = value;
				numElements++;
			}
			else
			{
				data = new int[1];
				data[0] = value;
				allocatedMemory = numElements = 1;
			}
		}

		int Pop(){
			if (numElements != NULL)
				return data[numElements - 1];
			else
				return NULL;
		}

		void Insert(const int value, const unsigned int position){
			
				if (position < numElements)
				{
					Reallocate(allocatedMemory+1);
					
					int pos = position; //Error with the for, we can't use an unsiged int. Provisional solution.
					for (int i = numElements; i > pos; i--)
					{	
						data[i + 1] = data[i];
					}
				}
				else
				{
					Reallocate(position);
				}
				data[position] = value;
				numElements++;
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