using System;
using System.Collections.Generic;
using System.IO;
class Solution
{
    static void ProcessMatrix(List<int[]> Mat)
    {
        // Verify Max on rows
        for (int i = 0; i < Mat.Count; ++i)
        {
            int maxL = 0;
            int maxR = 0;
            int[] tmp = new int[Mat.Count];
            for (int j = 0; j < Mat.Count; ++j)
            {
                int curr = Mat[i][j];
                if (Mat.Count/2 > j)
                {
                    maxL += curr;
                }
                else
                {
                    maxR += curr;
                }

                tmp[j] = curr;
            } 

            //Flip
            if (maxR > maxL)
            {
                for (int j = 0; j < Mat.Count; ++j)
                {
                    Mat[i][j] = tmp[Mat.Count - 1 - j];
                }
            }
        }

        // Print Total
        int totalMax = 0; 
        for (int i = 0; i < Mat.Count/2; ++i)
        {
            for (int j = 0; j < Mat.Count/2; ++j)
            {
                totalMax += Mat[i][j];
            }
        }

        Console.WriteLine(totalMax);
    }

    static void Main(String[] args)
    {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution */
        int q = Int32.Parse(Console.ReadLine());
        
        // For all queries q
        for (int i = 0; i < q; ++i)
        {
            int size = 2 * Int32.Parse(Console.ReadLine());

            List<int[]> Mat = new List<int[]>(size);
            for (int j = 0; j < size; ++j)
            {
                Mat.Add(Array.ConvertAll(Console.ReadLine().Split(' '), Int32.Parse));
            }


            // Process Matrix
            ProcessMatrix(Mat);
        }
    }
}