#include "pch.h"

#include "CppUnitTest.h"

#include "C:\Users\38063\source\repos\LABA2\LABA2\pervoe.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest

{

	TEST_CLASS(Calculate_Tests)

	{

	public:

		TEST_METHOD(calculate_get2and4_3returned)

		{

			int n = 5;

			int x = -2;

			int expected = 0;

			int actual = calculate(n, x);

			Assert::AreEqual(expected, actual);

		}

	public:

		TEST_METHOD(calculate_get3and5_2eturned)

		{

			int n = 3;

			int x = 3;

			int expected = 51;

			int actual = calculate(n, x);

			Assert::AreEqual(expected, actual);

		}

	};

	TEST_CLASS(CheckValidParams_Tests)

	{

	public:

		TEST_METHOD(checkValidParamc_get2and1and3_Truereturned)

		{

			int n = 2;

			int a = 1;

			int b = 3;

			try

			{

				checkValidParams(n, a, b, 1);

				Assert::IsTrue(true);

			}

			catch (...)

			{

				Assert::Fail();

			}

		}

	public:

		TEST_METHOD(checkValidParamc_get1and4and2_Failreturned)

		{

			int n = 1;

			int a = 4;

			int b = 2;

			try

			{

				checkValidParams(n, a, b, 1);

				Assert::Fail();

			}

			catch (...)

			{

				Assert::IsTrue(true);

			}

		};

	};

}