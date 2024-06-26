#include <bits/stdc++.h>
using namespace std;

class Solution
{
protected:
    string newCountAndSayString(string &str)
    {
        int countOccurrence = 0;
        string countAndSayStr = "";
        int n = str.length(), ind = 0;

        while (ind < n)
        {
            int count = 0;
            char ch = str[ind];

            while (ind < n && str[ind] == ch)
            {
                count++;
                ind++;
            }

            countAndSayStr += to_string(count) + string(1, ch);
        }

        return countAndSayStr;
    }

public:
    string countAndSay(int n)
    {
        if (n == 1)
            return "1";

        string prevStr = countAndSay(n - 1);
        string currStr = newCountAndSayString(prevStr);

        return currStr;
    }
};

int main()
{

    return 0;
}