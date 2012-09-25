#include "stdafx.h" 

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace BitTwittering
{
	[TestClass]
	public ref class UnitTest1
	{
	private:
		TestContext^ testContextInstance;

	public: 
		/// <summary>
		///Gets or sets the test context which provides
		///information about and functionality for the current test run.
		///</summary>
		property Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ TestContext
		{
			Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ get()
			{
				return testContextInstance;
			}
			System::Void set(Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ value)
			{
				testContextInstance = value;
			}
		};

		#pragma region Additional test attributes
		//
		//You can use the following additional attributes as you write your tests:
		//
		//Use ClassInitialize to run code before running the first test in the class
		//[ClassInitialize()]
		//static void MyClassInitialize(TestContext^ testContext) {};
		//
		//Use ClassCleanup to run code after all tests in a class have run
		//[ClassCleanup()]
		//static void MyClassCleanup() {};
		//
		//Use TestInitialize to run code before running each test
		//[TestInitialize()]
		//void MyTestInitialize() {};
		//
		//Use TestCleanup to run code after each test has run
		//[TestCleanup()]
		//void MyTestCleanup() {};
		//
		#pragma endregion 


		//Given n & m, insert m into n starting at j and ending at i
		[TestMethod]
		void GIVEN_TwoNumbers_WHEN_InsertingOneNumberIntoAnother_THEN_NumberGetsInserted()
		{
			int n = 2051; //100000000011
			int m = 60;	//111100
			int i = 2;
			int j = 7;

			int diff = n - (n>>i<<i); 
			n = n >> (j + 1) << (j + 1);

			int result = n + (m << i) + diff;

			Assert::AreEqual<int>(result, 2291);
		};

		//Given n & m, insert m into n starting at j and ending at i
		[TestMethod]
		void GIVEN_TwoNumbers_WHEN_InsertingOneNumberIntoAnother_THEN_NumberGetsInsertedAnotherWay()
		{
			int n = 2051; //100000000011
			int m = 60;	//111100
			int i = 2;
			int j = 7;

			int allOnes = ~0;
			int left = allOnes << (j+1);
			int right = (1 << i) - 1;
			int mask = left + right;

			int cleared = n & mask;
			int shifted = m << i;
			int result = cleared | shifted;
			
			Assert::AreEqual<int>(result, 2291);
		};
	};
}
