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
            vector<T> tmp;
            for (int j = 0; j <= i; ++j)
            {
                tmp.pop_back(vec[j]);
            }

            // push back into meta
            MetaArray->push_back(tmp);
        }

        return MetaArray;
    }
};

int main()
{
    cout << "Return all subsets of a set" << endl;







    return 0;
}