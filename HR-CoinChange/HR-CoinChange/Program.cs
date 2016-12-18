using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class Solution
{
    static int[,] DP;
    static public int CountCoins(int N, int[] coins, int M)
    {
        if (N < 0 || M < 0)
        {
            return 0;
        }

        if (N == 0)
        {
            return 1;
        }

        if (DP[N,M] > 0)
        {
            return DP[N,M];
        }

        DP[N,M] = CountCoins(N, coins, M - 1) + CountCoins(N - coins[M], coins, M);
        
        return DP[N,M];
    }
    static void Main(string[] args)
    {
        string[] ln = Console.ReadLine().Split(' ');
        int N = Convert.ToInt32(ln[0]);
        int M = Convert.ToInt32(ln[1]);

        ln = Console.ReadLine().Split(' ');
        int[] coins = Array.ConvertAll(ln, s => int.Parse(s));

        DP = new int[N + 1, M];
        int count = CountCoins(N, coins, M - 1);
        Console.WriteLine(count);



    }
}

