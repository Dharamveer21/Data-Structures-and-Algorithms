#include <bits/stdc++.h>
using namespace std;

/*
Approach -- Here we don't need repeated elements Hence , We will take a unordered set to store the elements
Then we start traversing the array & maintain a maxLen , if we find a variable next to our variable we add its 
Length & search for that new element & continue until we don't get any required element & update maxLen .
If we check the any element whose previous (like for 7 if 6 is already present) is present in the array we will
not check for it -- because we have already checked for its previous , it will also be counted there .
*/

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        unordered_set<int> st;
        int maxLen = 1;

        for (int num : nums)
        {
            st.insert(num);
        }

        for (int num : nums)
        {
            int prev = num - 1;
            unordered_set<int>::iterator it = st.find(prev);

            if (it == st.end())
            {
                int currNum = num + 1;
                int len = 1;

                while (st.find(currNum) != st.end())
                {
                    len++;
                    currNum++;
                }

                maxLen = max(maxLen, len);
            }
        }

        return maxLen;
    }
};

// TC : O(2 * N) = O(N)
// SC : O(N)

int main()
{

    return 0;
}