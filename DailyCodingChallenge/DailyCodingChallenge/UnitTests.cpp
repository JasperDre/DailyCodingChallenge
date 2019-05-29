#include "pch.h"
#include "CppUnitTest.h"
#include <array>
#include <iostream>
#include <stack>
#include <unordered_set>
#include "../ChallengeSource/Person.h"
#include "../ChallengeSource/Person.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DailyCodingChallenge
{
	TEST_CLASS(DailyCodingChallenge)
	{
	public:
		
		// Define a person with an identity and print their name.
		TEST_METHOD(TestMethod1)
		{
			std::string name = "Bill";
			Person person(name);
			Assert::AreEqual(name, person.GetName());
		}

		// Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.
		TEST_METHOD(TestMethod2)
		{
			// STD array for input method
			std::array<int, 5> input = { 1, 2, 3, 4, 5 };

			int* expected = new int[5] { 120, 60, 40, 30, 24 };
			int* left = new int[sizeof(int) * 5];
			int* right = new int[sizeof(int) * 5];
			int* output = new int[sizeof(int) * 5];

			left[0] = 1;
			right[4] = 1;

			for (unsigned int i = 1; i < 5; i++)
			{
				left[i] = input[i - 1] * left[i - 1];
			}

			for (int j = 3; j >= 0; j--)
			{
				right[j] = input[j + 1] * right[j + 1];
			}

			for (unsigned int i = 0; i < 5; i++)
			{
				output[i] = left[i] * right[i];
			}

			Assert::AreSame(output, expected);
		}
		
		// Given a string expression, find whether the given expression is balanced or not.
		TEST_METHOD(TestMethod3)
		{
			std::string inputTrue = "{[()]}";
			std::string inputFalse = "{{[]";
			std::string openExpressions = "[{(";
			std::string closeExpressions = "]})";

			inputTrue.erase(remove(inputTrue.begin(), inputTrue.end(), ' '), inputTrue.end());

			std::stack<int> scanner;

			for (size_t i = 0; i < inputTrue.size(); i++)
			{
				if (openExpressions.find(inputTrue[i]) != std::string::npos)
				{
					scanner.push(inputTrue[i]);
				}

				if (closeExpressions.find(inputTrue[i]) != std::string::npos)
				{
					scanner.pop();
				}
			}

			Assert::AreEqual((int)scanner.size(), 0);
		}
		
		// Given a sum, find the possible solutions.
		TEST_METHOD(TestMethod4)
		{
			int sum = 8;
			std::vector<int> input = { 1, 2, 4, 4 };
			std::unordered_set<int> complements;

			for (size_t i = 0; i < input.size(); i++)
			{
				Assert::IsTrue(complements.find(input[i]) != complements.end());

				complements.insert(sum - input[i]);
			}
		}
	};
}
