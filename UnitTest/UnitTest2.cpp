#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Punt2D/DynArray.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(DynArrayT){
public:
	TEST_METHOD(Reallocate)
	{
		DynArray<int> arr;

		arr.Reallocate(10);

		arr.Reallocate(12);

		Assert::IsTrue(arr.getAllocatedMemory() == 12);
	}
	

	TEST_METHOD(PushBack)
	{
		DynArray<int> arr;

		for (int i = 0; i < 6; i++)
		{ 
			arr.PushBack(i);
		}

		Assert::IsTrue(arr[0] == 0 && arr[1] == 1 && arr[4] == 4 && arr[5] == 5);
	}
	

	TEST_METHOD(Insert)
	{
		DynArray<int> array;

		for (int i = 0; i < DYN_ARRAY_BLOCK_SIZE; ++i)
		{
			array.PushBack(i);
		}

		array.Insert(999, 3);
		array.Insert(888, 17);
		array.Insert(777, 50);

		Assert::IsFalse(array.Insert(777, 50));
		Assert::AreEqual((int)array.getAllocatedMemory(), DYN_ARRAY_BLOCK_SIZE * 2);
		Assert::AreEqual((int)array[3], 999);
		Assert::AreEqual((int)array[17], 888);

	}

	

	};
}