using System;

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

        static void Main(string[] args)
        {
            Solution sol = new Solution(); 
            Console.WriteLine(sol.HasAlternatingBits(23452353));
            Console.WriteLine(sol.HasAlternatingBits(7));
            Console.WriteLine(sol.HasAlternatingBits(11));
            Console.WriteLine(sol.HasAlternatingBits(10));
            Console.WriteLine(sol.HasAlternatingBits(123));
            Console.WriteLine(sol.HasAlternatingBits(0));
            Console.WriteLine(sol.HasAlternatingBits(11));

        }
    }


}
