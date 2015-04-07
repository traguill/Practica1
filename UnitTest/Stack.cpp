#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Punt2D/Stack.h"
#include "../Punt2D/Qeue.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(Stack1)
	{
	public:
		
		TEST_METHOD(StackTest)
		{
			Stack<int> s;

			s.Push(1);
			s.Push(2);
			s.Push(3);

			Assert::IsTrue(s.Pop() == 3);
			Assert::IsTrue(s.Pop() == 2);
			Assert::IsTrue(s.Pop() == 1);

		}

	};
	TEST_CLASS(Qeue1)
	{
	public:

		TEST_METHOD(QeueTest)
		{
			Qeue<int> s;

			s.Push(1);
			s.Push(2);
			s.Push(3);

			int result;
			s.Pop(result);
			Assert::IsTrue(result == 1);
			s.Pop(result);
			Assert::IsTrue(result == 2);
			s.Pop(result);
			Assert::IsTrue(result == 3);

		}

	};

}