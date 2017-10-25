﻿using System;

namespace LC_BitStringEven
{
    public class Solution
    {
        public bool HasAlternatingBits(int n)
        {
            int prevFlag = n % 2;
            int altFlag = prevFlag - 1;
            while (n > 0){
                if (altFlag == prevFlag){
                    return false;
                }

                n = n >> 1;
                altFlag = prevFlag;
                prevFlag = n % 2;
            }

            return true;
        }

        // Does not work :(
        public bool HasAlternatingBits2(int n)
        {
            int mask1 = 0;
            int bit0 = 0;
            for (int i = 0; i < sizeof(int) * 8; ++i){
                mask1 |= (bit0 << i);
                bit0 = (bit0 == 0) ? 1 : 0;
            }

            if (n % 2 == 0){
                return (n & (mask1 >> 1)) == 0;
            }
            return ((n & mask1) == 0);
        }

        static void Main(string[] args)
        {
            Solution sol = new Solution(); 
            Console.WriteLine(sol.HasAlternatingBits2(8));

        }
    }


}
