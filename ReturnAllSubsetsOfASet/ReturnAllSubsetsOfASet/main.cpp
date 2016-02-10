////////////////////////////////////////////////////////////////
// Main - Return all Subsets of a Set. 

#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    template<typename T>
    static  vector< vector<T> >* ReturnAllSubsets(vector<T> &vec)
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
};

int main()
{
    cout << "Return all subsets of a set" << endl;
    vector<int> test = { 1,2,3,4,5 };
    vector<vector<int>> *MySubsets = Solution::ReturnAllSubsets(test);





    delete MySubsets;
    return 0;
}