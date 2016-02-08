////////////////////////////////////////////////////////////////
// Main: Sieve of Eratosthenes

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Method for find all primes up until some value of 'n'
// Process:
// - Take fist prime = 2, and remove all multiples. 
// - Find next prime, and remove all multiples.
// - continue until prime > sqrt(n). 
class SieveofE
{
public:
    SieveofE(int nMax) :
        mMax(nMax)
    {
        // Build Initial list of numbers
        for (int i = 2; i <= nMax; ++i)
        {
            mNumberArray.push_back(i);
        }
        
        mPrimes.push_back(2);

        // Init and make primes
        GetAllPrimes();
    }
    
    // Retrun prime vector
    vector<int> getPrimes()
    {
        return mPrimes;
    }


private:

    // Var
    int mMax;
    vector<int> mNumberArray;
    vector<int> mPrimes;

    // Methods
    // Build Prime array
    void GetAllPrimes()
    {
        while (mPrimes.back() < sqrt(mMax))
        {
            // Filter all multiples of prime
            filterPrimes();

            // Add the next prime to vector. 
            findNextPrime();
        }
    }

    // Filter all primes in array and set to -1. 
    void filterPrimes()
    {
        int prime = mPrimes.back();
        for (int i = prime*prime; i < mMax; i += prime)
        {
            mNumberArray[i] = -1;
        }
    }

    // Find the next prime and add to mPrimes array. 
    void findNextPrime()
    {
        int prime = mPrimes.back();
        int i = prime + 1;
        while (mNumberArray[i] < 0)
        {
            ++i;
        }

        mPrimes.push_back(mNumberArray[i]);
    }
};

int main()
{
    cout << "Sieve of Eratosthenes implementation for finding all primes." << endl;



    return 0;
}