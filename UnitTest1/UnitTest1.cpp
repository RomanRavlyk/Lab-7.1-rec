#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 7.1 rec/Lab 7.1 rec.cpp" // Replace with the actual path and file name

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestSort)
		{

			const int rowCount = 3;
			const int colCount = 4;
			int** testMatrix = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				testMatrix[i] = new int[colCount];

			testMatrix[0][0] = 5;
			testMatrix[0][1] = 8;
			testMatrix[0][2] = 3;
			testMatrix[0][3] = 7;

			testMatrix[1][0] = 2;
			testMatrix[1][1] = 6;
			testMatrix[1][2] = 9;
			testMatrix[1][3] = 1;

			testMatrix[2][0] = 4;
			testMatrix[2][1] = 10;
			testMatrix[2][2] = 3;
			testMatrix[2][3] = 7;


			Sort(testMatrix, rowCount, colCount);


			Assert::AreEqual(2, testMatrix[0][0]);
			Assert::AreEqual(4, testMatrix[1][0]);
			Assert::AreEqual(5, testMatrix[2][0]);


			for (int i = 0; i < rowCount; i++)
				delete[] testMatrix[i];
			delete[] testMatrix;
		}
	};
}