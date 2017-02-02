using System;
using System.Collections.Generic;
using System.IO;
class Solution
{
    static void nextMove(int n, int r, int c, String[] grid)
    {
    }
    static void Main(String[] args)
    {
        int n;

        n = int.Parse(Console.ReadLine());
        String pos;
        pos = Console.ReadLine();
        String[] position = pos.Split(' ');
        int[] int_pos = new int[2];
        int_pos[0] = Convert.ToInt32(position[0]);
        int_pos[1] = Convert.ToInt32(position[1]);
        String[] grid = new String[n];
        for (int i = 0; i < n; i++)
        {
            grid[i] = Console.ReadLine();
        }

        nextMove(n, int_pos[0], int_pos[1], grid);

    }
}