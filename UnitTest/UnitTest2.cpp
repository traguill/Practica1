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
		DynArray arr;

		arr.Reallocate(10);

		arr.Reallocate(12);

		Assert::IsTrue(arr.getAllocatedMemory() == 12);
	}
	

	TEST_METHOD(PushBack)
	{
		DynArray arr;

		for (int i = 0; i < 6; i++)
		{ 
			arr.PushBack(i);
		}

		Assert::IsTrue(arr[0] == 0 && arr[1] == 1 && arr[4] == 4 && arr[5] == 5);
	}

	TEST_METHOD(Insert)
	{
		DynArray arrEmpty, arrBegin, arrFinal, arrMiddle;

		arrEmpty.Insert(1, 3);

		for (int i = 0; i < 6; i++)
		{
			arrBegin.PushBack(i);
			arrFinal.PushBack(i);
			arrMiddle.PushBack(i);
		}

		arrBegin.Insert(9, 0);
		arrFinal.Insert(9, 5);
		arrMiddle.Insert(9, 3);

		Assert::IsTrue(arrEmpty[3] == 1);
		Assert::IsTrue(arrBegin[0] == 9 && arrBegin[6] == 5 && arrBegin[3] == 4);
		Assert::IsTrue(arrFinal[6] == 9 && arrFinal[0] == 0 && arrFinal[3] == 3);
		Assert::IsTrue(arrMiddle[3] == 9 && arrMiddle[0] == 0 && arrMiddle[6] == 5);

	}

	

	};
}