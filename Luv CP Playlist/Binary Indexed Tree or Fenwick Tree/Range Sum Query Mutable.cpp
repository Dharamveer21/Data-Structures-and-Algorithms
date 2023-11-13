#include <bits/stdc++.h>
using namespace std;

/*
We can solve this problem using binary index tree
initialize an bit array & an update & sumRange function on it
*/

class NumArray
{
private:
    int n;
    vector<int> arr;
    vector<int> bit;

    int sum(int ind)
    {
        // max bit we can remove is all , when all bits are set
        // any number can have atmost log n bits -- so its worst case time complexity becomes log n

        int ans = 0;

        for (; ind > 0; ind = (ind - (ind & (-ind))))
        {
            ans += bit[ind];
        }

        return ans;
    }

public:
    NumArray(vector<int> &nums)
    {
        n = nums.size();
        arr.resize(n + 1, 0);
        bit.resize(n + 1, 0);
        
        for (int i = 0; i < n; i++)
        {
            int val = nums[i];
            update(i, val);
        }
        
        for (int i = 0; i < n; i++)
        {
            int val = nums[i];
            arr[i + 1] = val;
        }
    }

    void update(int index, int val)
    {
        index = index + 1;
        val = val - arr[index];
        arr[index] += val;

        for (; index <= n; index = (index + (index & (-index))))
        {
            bit[index] += val;
        }
    }

    int sumRange(int left, int right)
    {
        // sum right - sum (left-1) = sum range
        right = right + 1;

        return (sum(right) - sum(left));
    }
};

int main()
{

    return 0;
}