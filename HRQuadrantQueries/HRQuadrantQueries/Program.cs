using System;
using System.Collections.Generic;
using System.IO;
using System.Collections;
using System.Text;

public class Point
{
    public Point(int in_x, int in_y)
    {
        X = in_x;
        Y = in_y;
    }

    public int X { get; set; }
    public int Y { get; set; }

    public int GetQuadrant()
    {

        if (X > 0 && Y > 0)
        {
            return 0;
        }
        if (X < 0 && Y > 0)
        {
            return 1;
        }
        if (X < 0 && Y < 0)
        {
            return 2;
        }

        return 3;
    }
}

class Solution
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

        // Preprocess queries
        //   Count X and Y flips
        //   If odd then flip once
        //   Remove all others. 
        List<string> nQuerys = new List<string>();
        int[] XFlips = new int[n];
        int[] YFlips = new int[n];

        System.IO.StreamWriter foutput = new System.IO.StreamWriter("output.txt");
        for (int i = 0; i < q; ++i)
        {
            // Process query
            string rawQuery = Console.ReadLine();
            string[] sQuery = rawQuery.Split(' ');
            string type = sQuery[0];
            int q_i = Convert.ToInt32(sQuery[1]) - 1;
            int q_j = Convert.ToInt32(sQuery[2]) - 1;

            if (type == "C")
            {
                //nQuerys.Add(rawQuery);
                for (int k = 0; k < n; ++k) {
                    if (XFlips[k] % 2 > 0)
                    {
                        points[k].Y = -points[k].Y;
                    }
                    if (YFlips[k] % 2 > 0)
                    {
                        points[k].X = -points[k].X;
                    }

                    // Reset FLips
                    XFlips[k] = 0;
                    YFlips[k] = 0;
                }

                // Print Result
                // Processes points (inclusive) 
                int[] count = new int[4];
                for (int k = q_i; k <= q_j; ++k)
                {
                    if (type == "C")
                    {
                        count[points[k].GetQuadrant()]++;
                    }
                }

                // Print to console
                Console.WriteLine("{0} {1} {2} {3}", count[0], count[1], count[2], count[3]);
                StringBuilder line = new StringBuilder();
                line.AppendFormat("{0} {1} {2} {3}", count[0], count[1], count[2], count[3]);
                foutput.WriteLine(line);

            }
            else if (type == "X")
            {
                for (int j = q_i; j <= q_j; ++j)
                {
                    XFlips[j]++;
                }
            }
            else
            {
                for (int j = q_i; j <= q_j; ++j)
                {
                    YFlips[j]++;
                }
            }
        }

        // Close file
        foutput.Close();


        //for (int i = 0; i < nQuerys.Count; ++i)
        //{
        //    // Process Flips
        //    for (int k = 0; k < n; ++k)
        //    {
        //        if (XFlips[i][k] % 2 > 0)
        //        {
        //            points[k].Y = -points[k].Y;
        //        }

        //        if (YFlips[i][k] % 2 > 0)
        //        {
        //            points[k].X = -points[k].X;
        //        }
        //    }

        //    // Count Quadrants
        //    string[] sQuery = nQuerys[i].Split(' ');
        //    string type = sQuery[0];
        //    int q_i = Convert.ToInt32(sQuery[1]) - 1;
        //    int q_j = Convert.ToInt32(sQuery[2]) - 1;

        //    // Processes points (inclusive) 
        //    int[] count = new int[4];
        //    for (int k = q_i; k <= q_j; ++k)
        //    {
        //        if (type == "C")
        //        {
        //            count[points[k].GetQuadrant()]++;
        //        }
        //    }

        //    // Print count if type is "C"
        //    if (type == "C")
        //    {
        //        Console.WriteLine("{0} {1} {2} {3}", count[0], count[1], count[2], count[3]);
        //        StringBuilder line = new StringBuilder();
        //        line.AppendFormat("{0} {1} {2} {3}", count[0], count[1], count[2], count[3]);
        //        foutput.WriteLine(line);
        //    }
        //}



    }
}