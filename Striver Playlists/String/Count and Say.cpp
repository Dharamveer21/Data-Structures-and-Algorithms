#include <bits/stdc++.h>
using namespace std;

class Solution
{
protected:
    string newCountAndSayString(string &str)
    {
        int n = str.length();
        int first = 0,countOccurrence = 0;

        for(int ind=0;ind<n;ind++)
        {
            int curr = str[ind];

            if(curr != first)
            {
                

                first = curr;
                countOccurrence = 1;
            }

            else
            {
                countOccurrence++;
            }
        }
    }

public:
    string countAndSay(int n)
    {
        if (n == 1)
            return "1";

        string prevStr = countAndSay(n-1);
        string currStr = newCountAndSayString(prevStr);

        return currStr;    
    }
};

int main()
{
    
    return 0;
}