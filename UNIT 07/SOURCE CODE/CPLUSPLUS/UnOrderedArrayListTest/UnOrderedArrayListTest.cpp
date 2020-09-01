#include "pch.h"
#include "CppUnitTest.h"
#include "../UnOrderedArrayList/List.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnOrderedArrayListTest
{
	TEST_CLASS(UnOrderedArrayListTest)
	{
	public:
		
		TEST_METHOD(InitTest)
		{
			List L;
			Init(L);
			int init_size = 0;
			Assert::AreEqual(init_size, L.Size);
		}

		TEST_METHOD(IsEmptyTest)
		{
			List L;
			Init(L);
			Assert::IsTrue(IsEmpty(L));
		}


		TEST_METHOD(InsertTest)
		{
			List L;
			Init(L);
			Insert(10, L); Insert(15, L); Insert(20, L);
			Assert::AreEqual(3, L.Size);
			Assert::AreEqual(20, L.Item[L.Size - 1]);
			Assert::IsFalse(IsFull(L));
		}

		TEST_METHOD(DeleteTest)
		{
			List L;
			Init(L);
			Insert(10, L); Insert(15, L); Insert(20, L);
			Assert::AreEqual(3, L.Size);
			Assert::AreEqual(20, L.Item[L.Size - 1]);
			Assert::IsFalse(IsFull(L));
			Delete(15, L);
			Assert::AreEqual(2, L.Size);
			Assert::IsFalse(IsEmpty(L));

			while (!(IsEmpty(L))) {
				Delete(L.Item[0], L);
			}
			Assert::AreEqual(0, L.Size);
			Assert::IsTrue(IsEmpty(L));
		}

		TEST_METHOD(IsFullTest)
		{
			List L;
			Init(L);
			while (!(IsFull(L))) {
				Insert(10, L);
			}
			Assert::AreEqual(MaxSize, L.Size);
			Assert::IsTrue(IsFull(L));
		}

		TEST_METHOD(ShowDataTest)
		{
			List L;
			Init(L);
			Insert(10, L); Insert(15, L); Insert(20, L);
			Assert::AreEqual(3, L.Size);
			std::string Expected_Output = "10\t15\t20\t";

			//REDIRECT CONSOLE OUTPUT TO STRING STREAM
			/********************************************************/
			//change the underlying buffer and save the old buffer
			std::stringstream ss;
			auto old_buf = std::cout.rdbuf(ss.rdbuf());
			ShowData(L); //all the std::cout goes to ss

			std::cout.rdbuf(old_buf); //reset to std::cout
			/********************************************************/

			//std::string result = ss.str();
			std::string result = "";
			std::string itemValue;
			while (ss >> itemValue)
				result += itemValue + "\t";

			Logger::WriteMessage(Expected_Output.c_str());
			Logger::WriteMessage(result.c_str());
			Assert::AreEqual(Expected_Output, result);


		}



	};
}
