using System;
using System.Collections.Generic;
using System.IO;
using System.Collections;

namespace HRQuadrantQueries
{
	class MainClass
	{
		public static void Main(string[] args)
		{
			int n = Convert.ToInt32(Console.ReadLine().ToString());

			// Get and store all points
			List<Tuple<int, int>> points = new List<Tuple<int, int>>();
			for (int i = 0; i < n; ++i)
			{
				string[] arr_t = Console.ReadLine().Split(' ');
				int[] arr = Array.ConvertAll(arr_t, Int32.Parse);

				points.Add(new Tuple<int, int>(arr[0], arr[1]));
			}


			// Get number of queries and parse
			int q = Convert.ToInt32(Console.ReadLine().ToString());
			for (int i = 0; i < q; ++i)
			{
				// Process query
			}
		}
	}
}
