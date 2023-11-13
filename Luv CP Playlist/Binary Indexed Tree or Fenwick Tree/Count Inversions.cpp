#include <bits/stdc++.h>
using namespace std;

/*
This problem can be solved using two for loops but it will give us TLE , so we solve it by binary indexed trees
we know that inversion count is merely the count of numbers which are greater than the given number & present in the array before it
so it is based on comparison not on the absolute value of number

so the maximum distinct numbers present in an array can be N
so when the values of the numbers is very large we can convert them into the range of 0 to N
and it will not change the inversion count

now to find the inversion count we can use the fenwick tree , we can put the number of occurences of a particular number in the array till it in the index of fenwick tree which is equal to the numbers
in this way , we can easily find the total occurrences of all numbers smaller than a particular number in the array upto its index by just finding the sum of the bit arr upto that index (which is number in array)

the inversion count for an element of the array  = sum (N) - sum (that number)
where sum is the function for bit array
*/

class Solution
{
    int sum(int ind, vector<int> &bit)
    {
        int ans = 0;

        for (; ind > 0; ind = (ind - (ind & (-ind))))
        {
            ans += bit[ind];
        }

        return ans;
    }

    void update(int ind, int x, vector<int> &bit)
    {
        for (; ind < bit.size(); ind = (ind + (ind & (-ind))))
        {
            bit[ind] += x;
        }
    }

public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.

    long long int inversionCount(long long arr[], long long N)
    {
        int cnt = 1;
        int n = N;
        vector<int> nums(n + 1, 0);
        map<long long, int> element_val;

        for (int i = 0; i < n; i++)
        {
            long long x = arr[i];
            element_val[x] = 0;
        }

        for (auto &pr : element_val)
        {
            element_val[pr.first] = cnt;
            cnt++;
        }

        for (int i = 0; i < n; i++)
        {
            long long num = arr[i];
            int val = element_val[num];
            nums[i + 1] = val;
        }

        // The required array is created
        long long int ans = 0;
        vector<int> bit(cnt, 0);
        
        for (int i = 1; i <= n; i++)
        {
            int num = nums[i];
            ans = ans + sum(cnt - 1, bit) - sum(num, bit);
            update(num, 1, bit);
        }

        return ans;
    }
};

int main()
{

    return 0;
}