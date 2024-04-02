#include <bits/stdc++.h>
using namespace std;

/*
Approach -- We can make a character to character mapping from string "s" to string "t" . It should be a one to
one mapping that is 1 character of the string "s" must be mapped with exactly 1 character in "t" and same that
1 character of string "t" must be mapped with exactly 1 character in "s" . We have to use two arrays of size
256 to store the mapping from "s" to "t" and for mapping from "t" to "s" . If mapping is complete then is true .
*/

class Solution
{
public:
    bool isIsomorphic(string &s, string &t)
    {
        string &str1 = s, &str2 = t;
        bool isStringsIsomorphic = true;

        int *charMappingFromString1ToString2 = new int[256];
        int *charMappingFromString2ToString1 = new int[256];

        fill(charMappingFromString1ToString2, charMappingFromString1ToString2 + 256, -1);
        fill(charMappingFromString2ToString1, charMappingFromString2ToString1 + 256, -1);

        for (int ind = 0; ind < str1.size(); ind++)
        {
            char ch1 = str1[ind], ch2 = str2[ind];
            int index1 = ch1 - NULL, index2 = ch2 - NULL;

            int mapping1To2 = charMappingFromString1ToString2[index1];
            int mapping2To1 = charMappingFromString2ToString1[index2];

            int isMapped = (mapping1To2 == -1) + (mapping2To1 == -1);

            switch (isMapped)
            {
            case 0:
                isStringsIsomorphic = ((mapping1To2 != index2 || mapping2To1 != index1) ? false : isStringsIsomorphic);
                break;

            case 1:
                isStringsIsomorphic = false;
                break;

            case 2:
                charMappingFromString1ToString2[index1] = index2;
                charMappingFromString2ToString1[index2] = index1;
            }
        }
        
        delete[] charMappingFromString1ToString2;
        delete[] charMappingFromString2ToString1;
        return isStringsIsomorphic;
    }
};

// TC : O(N)
// SC : O(256)

int main()
{

    return 0;
}