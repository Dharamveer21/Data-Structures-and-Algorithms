#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sums(int ind, int sum, vector<int> &arr, vector<int> &all_sums)
    {
        if (ind == arr.size())
        {
            all_sums.push_back(sum);
            return;
        }

        // not include the index
        sums(ind + 1, sum, arr, all_sums);

        // include the index
        sum += arr[ind];
        sums(ind + 1, sum, arr, all_sums);
        sum -= arr[ind];
    }

    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> all_sums;
        sums(0, 0, arr, all_sums);
        return all_sums;
    }
};

int main()
{

    return 0;
}