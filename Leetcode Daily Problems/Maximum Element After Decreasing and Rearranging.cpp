#include <bits/stdc++.h>
using namespace std;

// sort the array -- to arrange them in required order after operations
// elements will start from 1 and goes to next natural numbers , if we find the next num then starts finding next to it
// otherwise if we find some numbers smaller than it , we will continue
// if we find num greater than req , convert it into req number & move to find next one

class Solution
{
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int to_find = 1, n = arr.size();

        for (int i = 0; i < n; i++)
        {
            if (arr[i] >= to_find)
            {
                to_find++;
            }
        }

        return (--to_find);
    }
};

int main()
{

    return 0;
}