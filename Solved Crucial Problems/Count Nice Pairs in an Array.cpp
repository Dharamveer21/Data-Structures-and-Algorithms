#include <bits/stdc++.h>
using namespace std;

/*
Approach --the given statement is nums[i] + rev (nums[j]) == nums[j] + rev(nums[i])
which also means that nums[i] - rev(nums[i]) == nums[j] - rev(nums[j])
hence we find the difference of each num & its reverse & store it in the array
Now, we just have to calculate the count of each element in new array & use nC2 formulae
for finding the no of pairs for that count , then we find this value for each count & aggregate them
*/

class Solution
{
public:
    const int M = 1e9 + 7;
     
    int reverse(int num)
    {
        int rev = 0;
    
        while (num)
        {
            int digit = num % 10;
            num = num / 10;
        
            rev = rev * 10 + digit;
        }

        return rev;
    }

    int countNicePairs(vector<int> &nums)
    {
        int n = nums.size();
        int totalPairs = 0;
        unordered_map<int, int> elementCount;

        for (int ind = 0; ind < n; ind++)
        {
            int num = nums[ind];
            int rev = reverse(num);

            int diff = num - rev;
            elementCount[diff]++;
        }

        // nc2 = n * (n-1) / 2
        for (auto element : elementCount)
        {
            int count = element.second;
            int pairs = ((count * 1LL * (count - 1)) / 2) % M;
            totalPairs = (totalPairs + 0LL + pairs) % M;
        }

        return totalPairs;
    }
};

// TC : O(N * avg(digit(nums[i])) + N) = O(N * 9) = O(N)
// SC : O(N)

int main()
{

    return 0;
}