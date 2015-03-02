#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Punt2D/Point2D.h"
#include "../Punt2D/Point2D.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(Point2DT)
	{
	public:
		
		//Methods

		TEST_METHOD(IsZero)
		{
			Point2D p, p2, p3, p4;
			p.x = 0;
			p.y = 0;

			p2.x = 4;
			p2.y = 0;

			p3.x = 0;
			p3.y = 4;

			p4.x = 4;
			p4.x = 4;

			Assert::IsTrue(p.IsZero() && !p2.IsZero() && !p3.IsZero() && !p4.IsZero());

		}
		TEST_METHOD(SetZero)
		{
			Point2D p,p2;

			p.x = 4;
			p.y = 4;
			p.SetZero();

			p2.SetZero();

			Assert::IsTrue(p.IsZero() && p2.IsZero());

		}
		TEST_METHOD(DistanceTo)
		{
			Point2D p1, p2;
			p1.SetZero();
			p2.x = 3;
			p2.y = 4;
			
			Assert::IsTrue(p1.DistanceTo(p2) == 5);

		}

		//Operators

		TEST_METHOD(OperatorSum)
		{
			Point2D p,p2,p3;
			p.SetZero();
			p2.x = 4;
			p2.y = 5;

			p3 = p + p2;

			Assert::IsTrue(p3.x == 4 && p3.y == 5);

		}

		TEST_METHOD(OperatorSubtraction)
		{
			Point2D p, p2, p3;
			p.SetZero();
			p2.x = 4;
			p2.y = 5;

			p3 = p - p2;

			Assert::IsTrue(p3.x == -4 && p3.y == -5);

		}

		TEST_METHOD(OperatorSumEqual)
		{
			Point2D p, p2;
			p.x = 4;
			p.y = 1;

			p2.x = 1;
			p2.y = 4;

			p += p2;

			Assert::IsTrue(p.x == 5 && p.y == 5);

		}

		TEST_METHOD(OperatorSubtractionEqual)
		{
			Point2D p, p2;
			p.x = 4;
			p.y = 1;

			p2.x = 1;
			p2.y = 4;

			p -= p2;

			Assert::IsTrue(p.x == 3 && p.y == -3);

		}

		TEST_METHOD(OperatorEqual)
		{
			Point2D p, p2, p3;
			p.x = 4;
			p.y = 1;

			p2.x = 4;
			p2.y = 1;

			p3.x = 1;
			p3.x = 1;

			Assert::IsTrue(p==p2);
			Assert::IsFalse(p == p3);

		}
		TEST_METHOD(OperatorNoEqual)
		{
			Point2D p, p2, p3;
			p.x = 4;
			p.y = 1;

			p2.x = 4;
			p2.y = 1;

			p3.x = 1;
			p3.x = 1;

			Assert::IsTrue(p != p3);
			Assert::IsFalse(p != p2);

		}


	};
}