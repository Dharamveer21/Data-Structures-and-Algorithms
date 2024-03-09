#include <bits/stdc++.h>
using namespace std;

/*
Approach 1 -- Here we can use two pointer approach , we will take 2 pointers for each array . Now we compare
the value of the nums1 & nums2 at these pointers . If the two values are equal we will return it otherwise we
will increase the pointer which is pointing to smaller value .

Approach 2 -- As the both arrays are monotonic , we can traverse smaller array first & search for its element
in the larger array using the binary search method . If we find it , return the number .

N -- length of smaller array , M -- length of larger array
*/

// Approach 1
class Solution
{
public:
    int getCommon(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size(), n2 = nums2.size();
        int index1 = 0, index2 = 0, commonNum = -1;

        while (index1 < n1 && index2 < n2)
        {
            int num1 = nums1[index1];
            int num2 = nums2[index2];

            int isTrue = (num1 == num2) + (num1 >= num2);

            switch (isTrue)
            {
            case 0:
                index1++;
                break;

            case 1:
                index2++;
                break;

            case 2:
                commonNum = num1;
                return commonNum;
            }
        }

        return commonNum;
    }
};

// TC : O(N + M)
// SC : O(1)

// Approach 2
class Solution
{
protected:
    bool isElementPresent(vector<int> &nums, int val)
    {
        int lo = 0, hi = nums.size() - 1;

        while (hi - lo > 1)
        {
            int mid = (lo + hi) >> 1;

            if (nums[mid] < val)
            {
                lo = mid + 1;
            }

            else
            {
                hi = mid;
            }
        }

        bool isPresent = ((nums[lo] == val) || (nums[hi] == val));
        return isPresent;
    }

public:
    int getCommon(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size(), n2 = nums2.size();

        if (n1 > n2)
        {
            return getCommon(nums2, nums1);
        }

        for (int ind = 0; ind < n1; ind++)
        {
            int num = nums1[ind];
            bool isPresent = isElementPresent(nums2, num);

            if (isPresent)
            {
                return num;
            }
        }

        return -1;
    }
};

// TC : O(N * log(M))
// SC : O(1)

int main()
{

    return 0;
}