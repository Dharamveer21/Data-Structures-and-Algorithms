#include <bits/stdc++.h>
using namespace std;

// C++ STL find and reverse functions
class Solution
{
public:
    string reversePrefix(string &word, char &ch)
    {
        string ::iterator firstOccurrenceOfCh = find(word.begin(), word.end(), ch);

        if (firstOccurrenceOfCh != word.end())
            reverse(word.begin(), firstOccurrenceOfCh + 1);

        return word;
    }
};

// TC : O(N)
// SC : O(1)

int main()
{

    return 0;
}