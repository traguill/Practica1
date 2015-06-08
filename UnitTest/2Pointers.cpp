#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Punt2D/List2P.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(List2PTest)
	{
	public:
		
		TEST_METHOD(Add2Pointers)
		{
			List2P<int> list;

			list.Add(4);
			list.Add(5);

			Assert::IsTrue(list.start->value == 4 && list.start->next->value == 5);
		}

		TEST_METHOD(Delete2Pointers)
		{
			List2P<int> list;

			list.Add(4);
			list.Add(5);

			list.Delete(list.end);

			Assert::IsTrue(list.end->value == 4 && list.Count() == 1);
		}

		TEST_METHOD(DeleteAll2Pointers)
		{
			List2P<int> list;

			list.Add(4);
			list.Add(5);
			list.Add(6);
			list.DeleteAll();

			Assert::IsTrue(list.end == list.start && list.Count() == 0);
		}

		TEST_METHOD(OperatorSumEqual)
		{
			List2P<int> list;

			list.Add(1);
			list.Add(2);
			list.Add(3);
			
			List2P<int> list2;
			list2.Add(4);
			list2.Add(5);
			list2.Add(6);

			list += list2;
			Assert::AreEqual((int)list.Count(), 6);
		}


	};
}