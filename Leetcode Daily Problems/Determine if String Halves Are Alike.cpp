#include <bits/stdc++.h>
using namespace std;

/*
Approach -- Traverse the string lower half & upper half & calculate the count of vowels
*/

class Solution
{
protected:
    bool isVowel(char ch)
    {
        ch = (ch | ' ');

        switch (ch)
        {
        case 'a':
            return true;

        case 'e':
            return true;

        case 'i':
            return true;

        case 'o':
            return true;

        case 'u':
            return true;
        }

        return false;
    }

    int vowelsCount(int start, int end, string &str)
    {
        int count = 0;

        for (int ind = start; ind <= end; ind++)
        {
            char ch = str[ind];
            count = count + (isVowel(ch) == 1);
        }

        return count;
    }

public:
    bool halvesAreAlike(string s)
    {
        int n = s.size();

        int countLeft = vowelsCount(0, n / 2 - 1, s);
        int countRight = vowelsCount(n / 2, n - 1, s);

        return (countLeft == countRight);
    }
};

// TC : O(N)
// SC : O(1)

int main()
{
    return 0;
}