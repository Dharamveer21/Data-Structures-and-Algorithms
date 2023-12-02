#include <bits/stdc++.h>
using namespace std;

/*
Approach -- Simple problem use pointers concept for comparing the integer & while loop for parallel traversing
*/

class Solution
{
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {
        int n1 = word1.size(), n2 = word2.size();
        int ind1 = 0, ind2 = 0, ptr1 = 0, ptr2 = 0;

        while ((ind1 < n1) && (ind2 < n2))
        {
            if (word1[ind1][ptr1++] != word2[ind2][ptr2++])
            {
                return false;
            }

            if (ptr1 == word1[ind1].size())
            {
                ind1++;
                ptr1 = 0;
            }

            if (ptr2 == word2[ind2].size())
            {
                ind2++;
                ptr2 = 0;
            }
        }

        if (ind1 < n1 || ind2 < n2)
        {
            return false;
        }

        return true;
    }
};

// N is size of min(word1,word2) & k is average size of string inside word1 or word2
// TC : O(N * K) , where N*K is the no of characters in the smaller string
// SC : O(1)

int main()
{

    return 0;
}