#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Punt2D/DynArray.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(DynArrayT){
public:
	TEST_METHOD(GetAllocatedMry)
	{
		DynArray arr;

		arr.Reallocate(10);

		arr.Reallocate(12);

		Assert::IsTrue(arr.getAllocatedMemory() == 12);
	}
	

	TEST_METHOD(PushBack)
	{
		DynArray arr;

		arr.PushBack(2);

		Assert::IsTrue(arr[0] == 2);
	}
	

	};
}