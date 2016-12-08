﻿using System;
using System.Collections.Generic;
using System.IO;
using System.Collections;

namespace HRQuadrantQueries
{
	public class Point
	{
		public Point(int in_x, int in_y)
		{
			X = in_x;
			Y = in_y;
		}

		public int X { get; set; }
		public int Y { get; set; }

		public int GetQuadrant() {

			if (X > 0 && Y > 0)
			{
				return 0; 
			}
			if (X < 0 && Y > 0)
			{
				return 1;
			}
			if (X < 0 && Y < 0) {
				return 2;
			}

			return 3;
		}
	}

	class MainClass
	{
		public static void Main(string[] args)
		{
			int n = Convert.ToInt32(Console.ReadLine().ToString());

			// Get and store all points
			List<Point> points = new List<Point>();
			for (int i = 0; i < n; ++i)
			{
				string[] arr_t = Console.ReadLine().Split(' ');
				int[] arr = Array.ConvertAll(arr_t, Int32.Parse);

				points.Add(new Point(arr[0], arr[1]));
			}


			// Get number of queries and parse
			int q = Convert.ToInt32(Console.ReadLine().ToString());
			for (int i = 0; i < q; ++i)
			{
				// Process query
				string[] sQuery = Console.ReadLine().Split(' ');
				string type = sQuery[0];
				int q_i = Convert.ToInt32(sQuery[1]) - 1;
				int q_j = Convert.ToInt32(sQuery[2]) - 1;

				// Processes points (inclusive) 
				int[] count = new int[4];
				for (int k = q_i; k <= q_j; ++k)
				{
					if (type == "C")
					{
						count[points[k].GetQuadrant()]++;
					}
					else if (type == "X")
					{
						points[k].Y = -points[k].Y;
					}
					else
					{							
						points[k].X = -points[k].X;
					}
				}

				// Print count if type is "C"
				if (type == "C") {
					Console.WriteLine("{0} {1} {2} {3}", count[0], count[1], count[2], count[3]);
				}
			}

			 
		}
	}
}