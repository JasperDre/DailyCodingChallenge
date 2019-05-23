#include "pch.h"
#include "CppUnitTest.h"
#include <array>
#include <iostream>
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

			int* expected = new int[input.size()] { 120, 60, 40, 30, 24 };
			int* left = new int[sizeof(int) * input.size()];
			int* right = new int[sizeof(int) * input.size()];
			int* output = new int[sizeof(int) * input.size()];

			left[0] = 1;
			right[input.size() - 1] = 1;

			for (unsigned int i = 1; i < input.size(); i++)
			{
				left[i] = input[i - 1] * left[i - 1];
			}

			for (int j = input.size() - 2; j >= 0; j--)
			{
				right[j] = input[j + 1] * right[j + 1];
			}

			for (unsigned int i = 0; i < input.size(); i++)
			{
				output[i] = left[i] * right[i];
			}

			Assert::AreEqual(output, expected);
		}
	};
}
