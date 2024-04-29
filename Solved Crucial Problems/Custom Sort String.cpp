#include <bits/stdc++.h>
using namespace std;

/*
Approach -- We can store the freq of all elements in string s & then put all them in the order given in the
order string . If will take O(N + 26) space for result array & for frequency array of size 26 .

But we can have a better approach , we can use a custom comparator . Where we can assign values as 0 , 1 , 2 ..
to the characters of the order string in the given order & comapre on basis of these numbers .
*/

class Solution
{
public:
    string customSortString(string order, string s)
    {
        int val = 0, *indexingOrder = new int[26];
        fill(indexingOrder, indexingOrder + 26, 26);

        for (char &ch : order)
        {
            int index = ch - 'a';
            indexingOrder[index] = val++;
        }
         
        auto customComparator = [&indexingOrder](char &ch1, char &ch2)
        {
            int index1 = indexingOrder[ch1 - 'a'];
            int index2 = indexingOrder[ch2 - 'a'];

            return (index1 < index2);
        };

        sort(s.begin(), s.end(), customComparator);

        delete[] indexingOrder;
        return s;
    }
};

// TC : O(N * log(N)) -- time complexity of sorting
// SC : O(26 + log(N)) -- sorting use O(log(N)) space complexity

int main()
{
    return 0;
}