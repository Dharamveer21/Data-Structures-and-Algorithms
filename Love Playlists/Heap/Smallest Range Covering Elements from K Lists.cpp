#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        vector<int> smallestRange;
        int n = nums.size(), *arrPointer = new int[n]{}, minValue = INT_MAX, maxValue = INT_MIN;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for (int ind = 0; ind < n; ind++)
        {
            arrPointer[ind] = 0;
            int val = nums[ind][0];

            minValue = min(minValue, val);
            maxValue = max(maxValue, val);

            minHeap.push({val, ind});
        }

        smallestRange = {minValue, maxValue};

        while (!minHeap.empty())
        {
            pair<int, int> node = minHeap.top();
            minHeap.pop();

            int val = node.first;
            int index = node.second;

            minValue = val;
                
            int newDiff = maxValue - minValue;
            int oldDiff = smallestRange[1] - smallestRange[0];

            if ((oldDiff > newDiff) || (oldDiff == newDiff && minValue < smallestRange[0]))
            {
                smallestRange = {minValue, maxValue};
            }

            int pointer = arrPointer[index];

            if ((++pointer) == nums[index].size())
            {
                break;
            }

            int num = nums[index][pointer];
            arrPointer[index] = pointer;

            maxValue = max(maxValue, num);
            minHeap.push({num, index});
        }

        delete[] arrPointer;
        return smallestRange;
    }
};

int main()
{

    return 0;
}