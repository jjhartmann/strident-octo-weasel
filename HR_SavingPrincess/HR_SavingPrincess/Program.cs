using System;
using System.Collections.Generic;
using System.IO;
public class Point
{
	public int mm = 0;
	public int mn = 0;
	public Point()
	{
		; //
	}

	public Point(int m, int n)
	{
		mm = m;
		mn = n;
	}

	public Point Diff(Point p)
	{
		int dm = mm - p.mm;
		int dn = mn - p.mn;
		return new Point(dm, dn);
	}
}
class Solution
{
	static void displayPathtoPrincess(int n, String[] grid)
	{
		Point pPos = new Point();
		Point mPos = new Point();

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				// Bot position
				if (grid[i * n + j] == "m")
				{
					mPos.mm = i;
					mPos.mn = j;
				}

				// Princess Position
				if (grid[i * n + j] == "p")
				{
					pPos.mm = i;
					pPos.mn = j;
				}
			}
		}

		// Determine Diff
		Point diff = mPos.Diff(pPos);

		// Print Navigation for rows.
		for (int i = diff.mm; i != 0; i = (i < 0) ? i + 1 : i - 1) {
			if (i < 0)
			{
				Console.WriteLine("UP");
			}
			else
			{
				Console.WriteLine("DOWN");
			}
		}

		// Print Navigation for cols.
		for (int i = diff.mn; i != 0; i = (i < 0) ? i + 1 : i - 1)
		{
			if (i < 0)
			{
				Console.WriteLine("LEFT");
			}
			else
			{
				Console.WriteLine("RIGHT");
			}
		}

	}
	static void Main(String[] args)
	{
		int m;

		m = int.Parse(Console.ReadLine());

		String[] grid = new String[m];
		for (int i = 0; i < m; i++)
		{
			grid[i] = Console.ReadLine();
		}

		displayPathtoPrincess(m, grid);
	}
}
