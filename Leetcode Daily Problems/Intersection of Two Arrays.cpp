#include <bits/stdc++.h>
using namespace std;

/*
Approach -- Here we can sort first array & use binary search to find a each element of second array in present
in first array . We can store the elements in a set to store unique elements .

But we can use a more space optimised approach , we can sort both arrays & use two pointers to traverse the
elements , if we find equal elements we add them in result otherwise move pointer having smaller element .
*/

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> uniqueIntersection;
        int n1 = nums1.size(), n2 = nums2.size();
        int index1 = 0, index2 = 0, prevCommon = -1;

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

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
                index1 = index1 + 1;
                index2 = index2 + 1;
                int currCommon = num1;

                if (currCommon == prevCommon)
                {
                    continue;
                }

                prevCommon = currCommon;
                uniqueIntersection.push_back(currCommon);
            }
        }

        return uniqueIntersection;
    }
};

// TC : O(N * log(N) + M * log(M) + N + M)
// SC : O(1) -- No extra Auxillary space used

int main()
{

    return 0;
}