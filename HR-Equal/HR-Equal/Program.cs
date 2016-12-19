using System;
using System.Collections.Generic;
using System.IO;
class Solution
{

    static void CountOps(int N, int[] C)
    {
        // Fnd min
        int MIN = Int32.MaxValue;
        for (int i = 0; i < N; ++i)
        {
            if (MIN > C[i])
            {
                MIN = C[i];
            }
        }

        // Normalize Array
        int Ops = 0;
        for (int i = 0; i < N; ++i)
        {
            while (C[i] > MIN)
            {
                if (C[i] - 1 == MIN)
                {
                    C[i] += -1;
                }
                else if (C[i] - 2 == MIN)
                {
                    C[i] += -2;
                }
                else
                {
                    C[i] += -5;
                }

                Ops++;
            }
        }

        int blm = 0;
        for (int i = 0; i < N; ++i)
        {
            if (C[i] < MIN)
            {
                blm++;
            }
        }

        if (blm > N / 2)
        {
            MIN = Int32.MaxValue;
            for (int i = 0; i < N; ++i)
            {
                if (MIN > C[i])
                {
                    MIN = C[i];
                }
            }

            for (int i = 0; i < N; ++i)
            {
                if (C[i] > MIN)
                {
                    if (C[i] - 1 == MIN)
                    {
                        C[i] += -1;
                    }
                    else
                    {
                        C[i] += -2;
                    }

                    Ops++;
                }
            }

            Console.WriteLine(Ops);
            return;
        }

        // Normalize Array
        for (int i = 0; i < N; ++i)
        {
            if (C[i] < MIN)
            {
                if (C[i] + 1 == MIN)
                {
                    C[i] += 1;
                }
                else
                {
                    C[i] += +2;
                }

                Ops++;
            }
        }


        Console.WriteLine(Ops);


    }

    static void Main(String[] args)
    {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution */
        string ln = Console.ReadLine();
        int TestN = Convert.ToInt32(ln);

        // Iterate through test cases
        for (int i = 0; i < TestN; ++i)
        {
            int N = Convert.ToInt32(Console.ReadLine());
            string[] lnArr = Console.ReadLine().Split(' ');
            int[] C = Array.ConvertAll(lnArr, Int32.Parse);

            CountOps(N, C);

        }




    }
}