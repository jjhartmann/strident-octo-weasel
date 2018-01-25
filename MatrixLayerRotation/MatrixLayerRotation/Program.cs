using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MatrixLayerRotation
{
    class Solution
    {
        private static int R;
        private static int N;
        private static int M;
        static void matrixRotation(int[][] matrix)
        {
            int evenNum = 0;
            if (M % 2 == 0 && N % 2 == 0)
            {
                evenNum = (M < N) ? M : N;
            }
            else
            {
                evenNum = (M % 2 == 0) ? M : N;
            }
            int circles = evenNum/2;

            List<List<int>> concentricCircles = new List<List<int>>(circles);

            for (int i = 0; i < circles; ++i)
            {
                int len = 2 * M + 2 * N - 4 - 8 * i;
                int mMax = M - 2*i;
                int nMax = N - 2*i;
                int j = i, k = i;

                List<int> circle = new List<int>(len);
                for (int index = 0; index < len; ++index)
                {
                    int val = matrix[j][k];
                    circle.Add(val);

                    if (index < mMax - 1) ++j;
                    else if (index < mMax + nMax - 2) ++k;
                    else if (index < 2*mMax + nMax - 3) --j;
                    else --k;
                }


                concentricCircles.Add(circle);
            }

            // Move concentric circles
            for (int i = 0; i < circles; i++)
            {
                int len = 2 * M + 2 * N - 4 - 8 * i;
                int mMax = M - 2 * i;
                int nMax = N - 2 * i;
                int j = i, k = i;
                int moveIdx = len - R % len;


                for (int index = 0; index < len; ++index)
                {
                    int val = concentricCircles[i][moveIdx % len];
                    matrix[j][k] = val;

                    if (index < mMax - 1) ++j;
                    else if (index < mMax + nMax - 2) ++k;
                    else if (index < 2 * mMax + nMax - 3) --j;
                    else --k;
                    moveIdx++;
                }
            }

            // Print to StdOut
            PrintMatrix(matrix);

        }

        static void PrintMatrix(int[][] mattrix)
        {
            for (int i = 0; i < M; ++i)
            {
                for (int j = 0; j < N; ++j)
                {
                    Console.Write("{0} ", mattrix[i][j]);
                }
                Console.WriteLine();
            }
        }

        static void Main(String[] args)
        {
            string[] tokens_m = Console.ReadLine().Split(' ');
            int m = Convert.ToInt32(tokens_m[0]);
            int n = Convert.ToInt32(tokens_m[1]);
            int r = Convert.ToInt32(tokens_m[2]);
            R = r;
            M = m;
            N = n;

            int[][] matrix = new int[m][];
            for (int matrix_i = 0; matrix_i < m; matrix_i++)
            {
                string[] matrix_temp = Console.ReadLine().Split(' ');
                matrix[matrix_i] = Array.ConvertAll(matrix_temp, Int32.Parse);
            }

            matrixRotation(matrix);
        }
    }
}
