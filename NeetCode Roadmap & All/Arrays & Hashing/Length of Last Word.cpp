#include <bits/stdc++.h>
using namespace std;

/*
Approach -- We can solve it using simple loops but it can also be solved using C++ STL . Here we can delete
trailing spaces and then find the first non space index after last space index . Ans is (size - that index) .
*/

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int indexOfLastNonSpaceCharacter = s.find_last_not_of(' ');
        int indexOfFirstSpaceAfterLastWord = indexOfLastNonSpaceCharacter + 1;

        s.erase(indexOfFirstSpaceAfterLastWord);
        int lengthOfStringAfterTrimSpacesFromLast = s.length();

        int indexOfFirstSpaceFromLastBeforeLastWord = s.find_last_of(' ');
        indexOfFirstSpaceFromLastBeforeLastWord = ((indexOfFirstSpaceFromLastBeforeLastWord == string::npos) ? -1 : indexOfFirstSpaceFromLastBeforeLastWord);
        int indexOfFirstCharacterOfLastWord = indexOfFirstSpaceFromLastBeforeLastWord + 1;

        int lengthOfLastWordOfString = lengthOfStringAfterTrimSpacesFromLast - indexOfFirstCharacterOfLastWord;
        return lengthOfLastWordOfString;
    }
};

// TC : O(N)
// SC : O(1)

int main()
{

    return 0;
}