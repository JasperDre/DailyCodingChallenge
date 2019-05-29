using System;
using System.Collections.Generic;
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
    }
}
