using System;
using System.Collections.Generic;
using System.Linq;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace DailyCodingChallengeCS
{
    [TestClass]
    public class UnitTests
    {
        // Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.
        [TestMethod]
        public void TestMethod1()
        {
            List<int> inputList = new List<int>() { 10, 3, 5, 6, 2 };
            int[] input = new int[5] { 10, 3, 5, 6, 2 };
            int[] expected = new int[5] { 180, 600, 360, 300, 900 };
            int[] left = new int[5];
            int[] right = new int[5];
            int[] products = new int[5];

            left[0] = 1;
            right[4] = 1;

            for (int i = 1; i < 5; i++)
            {
                left[i] = input[i - 1] * left[i - 1];
            }

            for (int j = 3; j >= 0; j--)
            {
                right[j] = input[j + 1] * right[j + 1];
            }

            for (int i = 0; i < 5; i++)
            {
                products[i] = left[i] * right[i];
            }

            CollectionAssert.AreEqual(products, expected);
        }

        // Given a string expression, find whether the given expression is balanced or not.
        [TestMethod]
        public void TestMethod2()
        {
            string inputTrue = "{[()]}";
            string inputFalse = "{[})){";
            string openExpressions = "{[(";
            string closeExpressions = "}])";

            inputTrue.Replace(" ", string.Empty);

            Stack<int> scanner = new Stack<int>();

            for (int i = 0; i < inputTrue.Length; i++)
            {
                if (openExpressions.Contains(inputTrue[i].ToString()))
                {
                    scanner.Push(inputTrue[i]);
                }
                else if (closeExpressions.Contains(inputTrue[i].ToString()))
                {
                    scanner.Pop();
                }
            }

            Assert.IsTrue(scanner.Count == 0);
        }

        // Calculate the sum of all numbers from 1 up to n.
        [TestMethod]
        public void TestMethod3()
        {
            int n = 12;
            int expected = 78;

            // O(n)
            int total = 0;

            for (int i = 0; i <= n; i++)
            {
                total += i;
            }

            // O(1)
            int total1 = 0;

            total1 = n * (n + 1) / 2;

            Assert.AreEqual(total1, expected);
        }

        // Given an array of integers, find the first missing positive integer in linear time and constant space. In other words, find the lowest positive integer that does not exist in the array. The array can contain duplicates and negative numbers as well.
        [TestMethod]
        public void TestMethod4()
        {
            int[] input = { 3, 4, -1, 1 };
            int expected = 2;
            int output = 1;

            HashSet<int> positiveNumbers = new HashSet<int>();

            for (int i = 0; i < input.Length; i++)
            {
                if (input[i] > 0)
                {
                    positiveNumbers.Add(input[i]);
                }
            }

            for (int i = 0; i < input.Length + 1; i++)
            {
                if (positiveNumbers.Contains(output))
                {
                    output++;
                }
                else break;
            }

            Assert.AreEqual(output, expected);
        }
    }
}
