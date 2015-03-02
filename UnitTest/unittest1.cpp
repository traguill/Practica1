#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Punt2D/Point2D.h"
#include "../Punt2D/Point2D.cpp"
#include "../Punt2D/String.h"
#include "../Punt2D/String.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(Point2DTest)
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

	TEST_CLASS(StringTest)
	{
	public:

		//Constructors

		TEST_METHOD(EmptyConst)
		{
			String s;
			
			Assert::IsTrue(s.Capacity() == 1);
		}

		TEST_METHOD(CharCConst)
		{
			char* c = "hola";
			String s(c);

			Assert::IsTrue(s.Capacity() == 5 && s.Length() == 4 && strcmp(c, s.GetString()) == 0 );
		}

		TEST_METHOD(StringConst)
		{
			String s("hola");
			String s2(s);

			Assert::IsTrue(s.Capacity() == 5 && s.Length() == 4 && strcmp(s2.GetString(), s.GetString()) == 0);
		}
		TEST_METHOD(OperatorEqualEqualChar)
		{
			char* c = "hola";
			String s(c);

			Assert::IsTrue(s==c);
		}
		TEST_METHOD(OperatorEqualEqualString)
		{
			String s("hola");
			String s2("hola");

			Assert::IsTrue(s == s2);
		}
		TEST_METHOD(OperatorNotEqualChar)
		{
			char* c = "hola";
			String s("bye");

			Assert::IsTrue(s != c);
		}
		TEST_METHOD(OperatorNotEqualString)
		{
			String s("hola");
			String s2("bye");

			Assert::IsTrue(s != s2);
		}
		TEST_METHOD(OperatorEqualChar)
		{
			char* c = "hola";
			String s("bye");
			String s2;

			s = c;
			s2 = c;

			Assert::IsTrue(s == c && s2 == c);
		}
		TEST_METHOD(OperatorEqualString)
		{
			String r("hola");
			String s("bye");
			String s2;

			s = r;
			s2 = r;

			Assert::IsTrue(s == r && s2 == r);
		}

		TEST_METHOD(OperatorSumEqualChar)
		{
			char* c = "bro";
			String s;
			String s2("hey");

			s += c;
			s2 += c;

			Assert::IsTrue(strcmp(s2.GetString(), "heybro") == 0);
		}

		TEST_METHOD(OperatorSumEqualString)
		{
			
			String s("hey");
			String s2("bro");

			s += s2;

			Assert::IsTrue(strcmp(s.GetString(), "heybro") == 0);
		}

		TEST_METHOD(Lenght)
		{
			String s("hola");

			Assert::IsTrue(s.Length() == 4);
		}

		TEST_METHOD(Capacity)
		{
			String s("hola");

			Assert::IsTrue(s.Capacity() == 5);
		}
		TEST_METHOD(GetString)
		{
			String s("hola");

			Assert::IsTrue(strcmp(s.GetString(), "hola") == 0);
		}

		TEST_METHOD(Clear)
		{
			String s("hola");
			s.Clear();
			Assert::IsTrue(s.Capacity() == 1);
		}

	};
}