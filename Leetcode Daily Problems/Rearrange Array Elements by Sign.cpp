#include <bits/stdc++.h>
using namespace std;

/*
Approach -- We will use two pointers as poistive index & negative index , all even indexes are +ve indexes
and all odd indexes are -ve indexes . We just have to traverse the array when we find +ve number we put it on
+ve index & update it by 2 . -ve number we put it on -ve index & update it by 2 . as there are equal number of
positive & negative numbers we finally end up placing all at correct position . Return the ans array .
*/

class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int n = nums.size();
        int posIndex = 0, negIndex = 1;
        vector<int> rearrangedArr(n);

        for (int ind = 0; ind < n; ind++)
        {
            int num = nums[ind];
            int isPositive = (num > 0);

            switch (isPositive)
            {
            case 0:
                rearrangedArr[negIndex] = num;
                negIndex += 2;
                break;

            case 1:
                rearrangedArr[posIndex] = num;
                posIndex += 2;
                break;
            }
        }

        return rearrangedArr;
    }
};

// TC : O(N)
// SC : O(N)

int main()
{

    return 0;
}