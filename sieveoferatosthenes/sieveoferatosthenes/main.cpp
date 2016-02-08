////////////////////////////////////////////////////////////////
// Main: Sieve of Eratosthenes

#include <iostream>
#include <vector>

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
    }
    
    vector<int> GetAllPrimes(int nMax)
    {

    }

private:
    int mMax;
    vector<int> mNumberArray;
    vector<int> mPrimes;
};

int main()
{
    cout << "Sieve of Eratosthenes implementation for finding all primes." << endl;



    return 0;
}