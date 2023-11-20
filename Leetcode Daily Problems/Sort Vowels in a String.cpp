#include <bits/stdc++.h>
using namespace std;

// sort the vowels & store there location

class Solution
{
public:
    bool isVowel(char ch)
    {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        {
            return true;
        }

        if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
        {
            return true;
        }

        return false;
    }

    string sortVowels(string s)
    {
        vector<int> vowelLocations, vowels;

        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];

            if (isVowel(ch))
            {
                vowelLocations.push_back(i);
                vowels.push_back(ch);
            }
        }

        sort(vowels.begin(), vowels.end());

        for (int i = 0; i < vowels.size(); i++)
        {
            char ch = vowels[i];
            int location = vowelLocations[i];

            s[location] = ch;
        }

        return s;
    }
};

int main()
{

    return 0;
}