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


class Node
{
    const int QSize = 4;
    int[] mQuad = new int[QSize];
    public int Start, End;
    public Node(int s, int e)
    {
        Start = s;
        End = e;
    }

    public Node(Node l, Node r)
    {
        Start = -1;
        End = -1;
        merge(l, r);
    }

    public Node()
    {
        Start = -1;
        End = -1;
    }

    public void Increment(int q)
    {
        if (q >= 0 && q < QSize)
            mQuad[q]++;
    }

    public void Decrement(int q)
    {
        if (q >= 0 && q < QSize)
            mQuad[q]--;
    }
    public void merge(Node l, Node r)
    {

        for (int i = 0; i < QSize; ++i)
        {
            mQuad[i] = l.mQuad[i] + r.mQuad[i];
        }
    }

    public int[] getArray()
    {
        return mQuad;
    }

}

class SegmentTree
{
    Point[] mPoints;
    Node[] mSegTree;
    int mSTSize;
    int mPSize;
    int mHeight;
    int mSChildren;
    int mMaxNodes;

    public SegmentTree(Point[] points, int n)
    {
        mPSize = n;
        mPoints = points;
        mHeight = (int) Math.Ceiling(Math.Log(n, 2));
        mSTSize = (int) Math.Pow(2, mHeight + 1) - 1;
        mSegTree = new Node[mSTSize];

        mSChildren = (int)Math.Pow(2, mHeight);
        mMaxNodes = mSChildren + mPSize;

        // Initialize the end nodes
        for (int i = mSChildren - 1, j = 0; j < mPSize; ++i, ++j) {
            mSegTree[i] = new Node(j + 1, j + 1);
            mSegTree[i].Increment(mPoints[j].GetQuadrant());
        }

        BuildTree(1, 1, mSChildren);
    }

    int GetLeftChild(int idx)
    {
        return idx * 2;
    }

    int GetRightChild(int idx)
    {
        return idx * 2 + 1;
    }
    
    // Build and merge tree
    private Node BuildTree(int idx, int sStart, int sEnd)
    {
        // Base
        if (idx >= mSChildren)
        {
            if (mSegTree[idx - 1] == null)
                return new Node(-1, -1);

            return mSegTree[idx - 1];
        }

        int leftIdx = GetLeftChild(idx);
        int rightIdx = GetRightChild(idx);
        int midpoint = (sStart + sEnd) / 2;

        Node left = BuildTree(leftIdx, sStart, midpoint);
        Node right = BuildTree(rightIdx, midpoint + 1, sEnd);

        // Merge
        mSegTree[idx - 1] = new Node(sStart, sEnd);
        mSegTree[idx - 1].merge(left, right);
        return mSegTree[idx - 1];  
    }

    // Query range
    public Node Query(int left, int right)
    {
        return Query(1, left, right);
    }

    private Node Query(int idx ,int left, int right)
    {
        Node seg = mSegTree[idx - 1];
        //if (left > seg.End || right < seg.Start || idx >= mSChildren + mPSize)
        //{
        //    // Search range is outside the query
        //    return returnNode;
        //}

        if (left <= seg.Start && right >= seg.End)
        {
            // Search range is within query, so return substree parent node
            if (mSegTree[idx - 1] == null)
                return new Node();

            return mSegTree[idx - 1];
        }

        int leftIdx = GetLeftChild(idx);
        int rightIdx = GetRightChild(idx);
        Node leftSeg = mSegTree[leftIdx - 1];
        Node rightSeg = mSegTree[rightIdx - 1];

        // Recurse on subtrees
        Node tmpLeft = leftIdx < mMaxNodes && left <= leftSeg.End ? 
            Query(idx * 2, left, right) : new Node();
        Node tmpRight = rightIdx < mMaxNodes && right >= rightSeg.Start ? 
            Query(idx * 2 + 1, left, right) : new Node();

        return new Node(tmpLeft, tmpRight); 
    }


    // Update Values for Points in Tree
    public void Update(int uBegin, int uEnd, bool xflip)
    {
        Update(1, 1, mSTSize - mSChildren + 1, uBegin, uEnd, xflip);

    }


    // Update this to do a range update
    //    Take in a range for udating the xflips and yflips
    //    Need to drill down to leafs and update them then merge
    //    Very similar to BuildTree
    private Node Update(int idx, int sStart, int sEnd, int uBegin, int uEnd, bool xflip)
    {
        if (idx >= mSChildren + mPSize)
            return new Node();

        // Update node if in range
        if (idx >= mSChildren && idx < mSChildren + mPSize && uBegin <= sStart && sEnd <= uEnd)
        {
            int mPidx = idx - mSChildren;
            // Get start quadrant
            int quadS = mPoints[mPidx].GetQuadrant();

            // Update point
            if (xflip)
                mPoints[mPidx].Y = -mPoints[mPidx].Y;
            else
                mPoints[mPidx].X = -mPoints[mPidx].X;

            // Get  end quadrant
            int quadE = mPoints[mPidx].GetQuadrant();

            mSegTree[idx - 1].Decrement(quadS);
            mSegTree[idx - 1].Increment(quadE);

            return mSegTree[idx - 1];
        }

        // If udix is out of range return. 
        if (uBegin > sEnd || uEnd < sStart || sStart == sEnd)
        {
            return mSegTree[idx - 1];
        }

        int midPoint = (sStart + sEnd) / 2;
        Node left = Update(idx * 2, sStart, midPoint, uBegin, uEnd, xflip);
        Node right = Update(idx * 2 + 1, midPoint + 1, sEnd, uBegin, uEnd, xflip);

        mSegTree[idx - 1].merge(left, right);
        return mSegTree[idx - 1];
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

        // Build Segment Tree
        SegmentTree sgTree = new SegmentTree(points.ToArray(), points.Count);


        // Get number of queries and parse
        int q = Convert.ToInt32(Console.ReadLine().ToString());

        // Preprocess queries
        //   Count X and Y flips
        //   If odd then flip once
        //   Remove all others. 
        bool[] XFlips = new bool[n + 1];
        bool[] YFlips = new bool[n + 1];

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
                //// Iterate through range and process flips for Count
                //// Only reset the values for the processed flips.
                int xprev = q_i;
                int yprev = q_i;
               

                for (int k = q_i + 1; k <= q_j + 1; ++k)
                {
                    if ((!XFlips[k] && XFlips[k - 1]) || (k == q_j + 1 && XFlips[k - 1]))
                    {
                        sgTree.Update(xprev + 1, k, true);
                    }
                    else if (XFlips[k] && !XFlips[k-1])
                    {
                        xprev = k;
                    }

                    if ((!YFlips[k] && YFlips[k - 1]) || (k == q_j + 1 && YFlips[k - 1]))
                    {
                        sgTree.Update(yprev + 1, k, false); 
                    }
                    else if (YFlips[k] && !YFlips[k - 1])
                    {
                        yprev = k;
                    }

                    // Reset FLips
                    XFlips[k - 1] = false;
                    YFlips[k - 1] = false;
                }

                // Print Result
                // Processes points (inclusive) 
                int[] count = sgTree.Query(q_i + 1, q_j + 1).getArray();

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
                    XFlips[j] = !XFlips[j];
                }


                //// Process query
                //sgTree.Update(q_i + 1, q_j + 1, true);
            }
            else
            {
                for (int j = q_i; j <= q_j; ++j)
                {
                    YFlips[j] = !YFlips[j];
                }

                //sgTree.Update(q_i + 1, q_j + 1, false);
            }
        }

        // Close file
        foutput.Close();

    }
}