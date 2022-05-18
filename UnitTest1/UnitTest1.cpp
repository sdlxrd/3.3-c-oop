#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\Misha\source\repos\3.3(c) oop\3.3(c) oop\Object.cpp"
#include "C:\Users\Misha\source\repos\3.3(c) oop\3.3(c) oop\Money.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
			
			Money a(0, 0), b( 0, 0), c(0, 0);
			double d = Object::getCount();
			Assert::AreEqual(d, 3.);
		}
	};
}
