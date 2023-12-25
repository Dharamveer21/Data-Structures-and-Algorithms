#include <bits/stdc++.h>
using namespace std;

/*
Approach -- It is a dp Problem where we have to find the num of ways , so at last there must be only one way for a string starting with
ind 'n' of length 0

Now as we know we have to check all ways of decoding , firstly take only one char at index ind . if it is valid decode then call the function for (ind+1)
also take two characters with ind , ind+1 -- if they both together also make a valid mapping then call the function for (ind+2)

add these two values is the total Number of ways of Decoding the array
*/

class Solution
{
public:
    // memoisation
    bool isMappingValid(string &str)
    {
        int len = str.length();

        if (len == 1 && str[0] != '0')
        {
            return true;
        }

        else if (len == 2)
        {
            if ((str[0] == '1') && (str[1] >= '0' && str[1] <= '9'))
            {
                return true;
            }

            else if ((str[0] == '2') && (str[1] >= '0' && str[1] <= '6'))
            {
                return true;
            }
        }

        return false;
    }

    int numOfDecodings(int ind, string &str, vector<int> &decodesCount)
    {
        int n = str.length();
        int totalDecodes = 0;

        if (decodesCount[ind] != -1)
        {
            return decodesCount[ind];
        }

        string firstDecode;
        firstDecode.push_back(str[ind]);

        if (isMappingValid(firstDecode))
        {
            totalDecodes += numOfDecodings(ind + 1, str, decodesCount);
        }

        if (ind != n - 1)
        {
            firstDecode.push_back(str[ind + 1]);

            if (isMappingValid(firstDecode))
            {
                totalDecodes += numOfDecodings(ind + 2, str, decodesCount);
            }
        }

        return decodesCount[ind] = totalDecodes;
    }

    int numDecodings(string s)
    {
        int n = s.length();
        vector<int> decodesCount(n + 1, -1);
        decodesCount[n] = 1;
        int decodes = numOfDecodings(0, s, decodesCount);
        return decodes;
    }

    // tabulation
    bool isMappingValid(string &str)
    {
        int len = str.length();

        if (len == 1 && str[0] != '0')
        {
            return true;
        }

        else if (len == 2)
        {
            if ((str[0] == '1') && (str[1] >= '0' && str[1] <= '9'))
            {
                return true;
            }

            else if ((str[0] == '2') && (str[1] >= '0' && str[1] <= '6'))
            {
                return true;
            }
        }

        return false;
    }

    int numDecodings(string s)
    {
        int n = s.length();
        vector<int> decodesCount(n + 1, 0);
        decodesCount[n] = 1;

        for (int ind = n - 1; ind >= 0; ind--)
        {
            int totalDecodes = 0;
            string firstDecode;
            firstDecode.push_back(s[ind]);

            if (isMappingValid(firstDecode))
            {
                totalDecodes += decodesCount[ind + 1];
            }

            if (ind != n - 1)
            {
                firstDecode.push_back(s[ind + 1]);

                if (isMappingValid(firstDecode))
                {
                    totalDecodes += decodesCount[ind + 2];
                }
            }

            decodesCount[ind] = totalDecodes;
        }

        int decodes = decodesCount[0];
        return decodes;
    }

    // space optimization
    bool isMappingValid(string &str)
    {
        int len = str.length();

        if (len == 1 && str[0] != '0')
        {
            return true;
        }

        else if (len == 2)
        {
            if ((str[0] == '1') && (str[1] >= '0' && str[1] <= '9'))
            {
                return true;
            }

            else if ((str[0] == '2') && (str[1] >= '0' && str[1] <= '6'))
            {
                return true;
            }
        }

        return false;
    }

    int numDecodings(string s)
    {
        int n = s.length();
        int nextDecodes1 = 0, nextDecodes2 = 1;

        for (int ind = n - 1; ind >= 0; ind--)
        {
            int totalDecodes = 0;
            string firstDecode;
            firstDecode.push_back(s[ind]);

            if (isMappingValid(firstDecode))
            {
                totalDecodes += nextDecodes1;
            }

            if (ind != n - 1)
            {
                firstDecode.push_back(s[ind + 1]);

                if (isMappingValid(firstDecode))
                {
                    totalDecodes += nextDecodes2;
                }
            }

            nextDecodes2 = nextDecodes1;
            nextDecodes1 = totalDecodes;
        }

        int decodes = nextDecodes1;
        return decodes;
    }
};

// TC : O(N) -- length of dp array , traversing it whole to fill it completely
// SC : O(1) -- only 2 variables in space optimised code

int main()
{

    return 0;
}