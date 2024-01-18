#include <bits/stdc++.h>
using namespace std;

/*
Approach -- store the count of each element in the hash array & sort it , check for adjacent element is equal
*/

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        vector<int> elementCount(2001, 0);

        for (int i = 0; i < arr.size(); i++)
        {
            elementCount[arr[i] + 1000] += 1;
        }

        sort(elementCount.begin(), elementCount.end());

        for (int i = 0; i < 2000; i++)
        {
            if (elementCount[i] == elementCount[i + 1] && elementCount[i] != 0)
            {
                return false;
            }
        }

        return true;
    }
};

// TC : O(N + 2000 * log(2000) + 2000) = O(N)
// SC : O(2000) = O(N)

int main()
{

    return 0;
}