////////////////////////////////////////////////////////////////
// Main - Return all Subsets of a Set. 

#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    // Contingent subsets. 
    template<typename T>
    static  vector< vector<T> >* ReturnAllContingentSubsets(vector<T> &vec)
    {
        vector<vector<T>> *MetaArray = new vector<vector<T>>(); // Don't Own

        for (int i = 0; i < vec.size(); ++i)
        {
            for (int j = i; j < vec.size(); ++j)
            {
                vector<T> tmp;

                for (int k = i; k <= j; ++k)
                    tmp.push_back(vec[k]);
    
                // push back into meta
                MetaArray->push_back(tmp);
            }
        }

        return MetaArray;
    }

    // All Possible subsets. 
    template<typename T>
    static  vector< vector<T> >* ReturnAllSubsets(vector<T> &vec)
    {
        vector<vector<T>> *MetaArray = new vector<vector<T>>(); // Don't Own
        return allSubsetsHelper(vec, MetaArray, vec.size()-1);
    }


    // All Possible Subsets Iterative
    template <typename T>
    static vector< vector <int> >* ReturnAllSubsetsItr(vector<T> &vec)
    {
        vector<vector<T>> *MetaArray = new vector<vector<T>>(); // Don't Own

        // Get the number of sets = 2^n
        int numberofSets = pow(2, vec.size());

        for (int i = 0; i < numberofSets; ++i)
        {
            MetaArray->push_back(convertBinToSet(vec, i));
        }

    }


private:
    // convert binary string to subset
    template <typename T>
    static vector<T> convertBinToSet(vector<int> &vec, int bin)
    {
        vector<T> tmp;
        for (int i = 0; i < vec.size(); ++i)
        {
            if (bin % 2)
            {
                tmp.push_back(vec[i]);
            }
        }

        return tmp;
    }

    template<typename T>
    static vector< vector<T> >* allSubsetsHelper(vector<T> &vec, vector< vector<T> > *mArray, int pos)
    {
        // Create empty set
        if (pos < 0)
        {
            vector<T> tmp;
            mArray->push_back(tmp);
            return mArray;
        }

        // Retrieve P_(N-1)
        mArray = allSubsetsHelper(vec, mArray, pos - 1);

        // Create new subsets and add to mArray
        T element = vec[pos];
        int MaxSize = mArray->size();
        for (int i = 0; i < MaxSize; ++i)
        {
            // Copy array
            vector<T> tmp = mArray->at(i);

            // Add new element
            tmp.push_back(element);


            // Add to P_N
            mArray->push_back(tmp);
        }

        return mArray;
    }

};

int main()
{
    cout << "Return all subsets of a set" << endl;
    vector<int> test = { 1,2,3,4,5 };
    vector<vector<int>> *MySubsets = Solution::ReturnAllSubsets(test);
    vector<vector<int>> *MySubsets2 = Solution::ReturnAllSubsets(test);





    delete MySubsets;
    delete MySubsets2;
    return 0;
}