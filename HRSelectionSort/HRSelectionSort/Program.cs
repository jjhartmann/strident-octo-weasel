using System;
using System.Collections.Generic;
using System.IO;
class Solution
{
	static void printArray(int[] ar, int n)
	{
		string str = ar[0].ToString();
		for (int k = 1; k < n; ++k)
		{
			str += (" " + ar[k].ToString());
		}

		Console.WriteLine(str);
	}

	static void insertionSort(int[] ar, int n)
	{

		for (int i = 1; i < n; ++i)
		{
			// Check for acsending order
			if (ar[i] < ar[i - 1])
			{
				int num = ar[i];
				int j = i - 1;
				while (j >= 0 && ar[j] > num)
				{
					ar[j + 1] = ar[j];
					--j;

					//printArray(ar, n);
				}

				ar[j + 1] = num;

				printArray(ar, n);
			}
		}

	}

	/* Tail starts here */
	static void Main(String[] args)
	{

		int _ar_size;
		_ar_size = Convert.ToInt32(Console.ReadLine());
		int[] _ar = new int[_ar_size];
		String elements = Console.ReadLine();
		String[] split_elements = elements.Split(' ');
		for (int _ar_i = 0; _ar_i < _ar_size; _ar_i++)
		{
			_ar[_ar_i] = Convert.ToInt32(split_elements[_ar_i]);
		}

		insertionSort(_ar, _ar_size);
	}
}
