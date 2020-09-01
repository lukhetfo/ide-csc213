#include "stdafx.h"
#include "CppUnitTest.h"
#include "../BankAccountExample/Account.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BankAccountExample
{		
	TEST_CLASS(BankAccountExample)
	{
	public:
		TEST_METHOD(CreateTest)
		{
			//arrange
			Account A;
			//act
			A.create(); 
			//assert
			Assert::IsTrue(A.balance == 0);
			

			//arrange
			Account B;
			//act
			B.create(1000);
			//assert
			Assert::IsTrue(B.balance == 1000);
		}

		TEST_METHOD(DepositTest)
		{
			//arrange
			Account A;
			A.create(1000);
			float expected_new_balance = 1500;

			//act
			A.deposit(500);

			//assert
			Assert::AreEqual(A.balance,
				expected_new_balance);

		}

		TEST_METHOD(WithdrawTest)
		{
			// arrange
			Account A;
			A.create(1000);
			float expected_new_balance = 700;

			// act
			A.withdraw(300);

			//assert
			Assert::AreEqual(A.balance,
				expected_new_balance);
		}


		TEST_METHOD(DisplayBalanceTest)
		{
			// arrange
			Account A;
			A.create(1000);
			std::string Expected_Output = "Balance is 1000 Emalangeni\n";

			//REDIRECT CONSOLE OUTPUT TO STRING STREAM
			/********************************************************/
			//change the underlying buffer and save the old buffer
			std::stringstream ss;
			auto old_buf = std::cout.rdbuf(ss.rdbuf());

			//act
			A.displayBalance(); //all the std::cout goes to ss

			std::cout.rdbuf(old_buf); //reset to std::cout
			/********************************************************/

			std::string result = ss.str();
			
			//assert
			Assert::AreEqual(Expected_Output, result);
		}


	};
}