using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
class Solution
{

    static int lonelyinteger(int[] a)
    {
        // Complete this function
    }

    static void Main(String[] args)
    {
        int n = Convert.ToInt32(Console.ReadLine());
        string[] a_temp = Console.ReadLine().Split(' ');
        int[] a = Array.ConvertAll(a_temp, Int32.Parse);
        int result = lonelyinteger(a);
        Console.WriteLine(result);
    }
}
