#include <bits/stdc++.h>
using namespace std;

class Solution
{
protected:
    string newCountAndSayString(string &str)
    {
        string countAndSayStr;
        int countOccurrence = 0;
        int n = str.length(), first = '0';

        for (int ind = 0; ind < n; ind++)
        {
            int curr = str[ind];

            if (curr != first)
            {
                string cnt = to_string(countOccurrence);
                countAndSayStr += cnt;
                countAndSayStr.push_back(first);

                first = curr;
                countOccurrence = 0;
            }

            countOccurrence++;
        }
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