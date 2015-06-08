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

	TEST_METHOD(InsertArray)
	{
		DynArray<int> array;

		for (int i = 0; i < 6; ++i)
		{
			array.PushBack(i);
		}

		DynArray<int> array2;

		for (int i = 0; i < 4; ++i)
		{
			array2.PushBack(i);
		}

		array.Insert(array2, 4);

		Assert::AreEqual((int)array[0], 0);
		Assert::AreEqual((int)array[1], 1);
		Assert::AreEqual((int)array[2], 2);
		Assert::AreEqual((int)array[3], 3);
		Assert::AreEqual((int)array[4], 0);
		Assert::AreEqual((int)array[5], 1);
		Assert::AreEqual((int)array[6], 2);
		Assert::AreEqual((int)array[7], 3);
		Assert::AreEqual((int)array[8], 4);
		Assert::AreEqual((int)array[9], 5);
		

	}

	

	};
}