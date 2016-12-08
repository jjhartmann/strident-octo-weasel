using System;

namespace HRCircularRotation
{
	class MainClass
	{
		public static void Main(string[] args)
		{
			string[] tokens_n = Console.ReadLine().Split(' ');
			int n = Convert.ToInt32(tokens_n[0]);
			int k = Convert.ToInt32(tokens_n[1]);
			int q = Convert.ToInt32(tokens_n[2]);

			// Edge case
			if (n == 0)
			{
				return;
			}

			string[] a_temp = Console.ReadLine().Split(' ');
			int[] a = Array.ConvertAll(a_temp, Int32.Parse);

			int Knorm = k % n;

			if (n == 1)
			{
				Console.WriteLine(a[0]);
				return;
			}

			for (int a0 = 0; a0 < q; a0++)
			{
				int m = Convert.ToInt32(Console.ReadLine());

				// Process the query
				int index = m - Knorm < 0 ? (n + m) - Knorm : m - Knorm;
				Console.WriteLine(a[index]);
			}


		}
	}
}
