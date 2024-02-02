#include <bits/stdc++.h>
using namespace std;

/*
Approach -- we have to generate all numbers having sequential digits & then put it into queue using bfs
then we can simultaneously check if is falls in the given range or not

As low >= 10 means the number 1 <= num <= 9 is not part of answer also we can't increase digit beyond 9
*/

class Solution
{
protected:
    bool isInRange(int num, int low, int high)
    {
        return (low <= num && num <= high);
    }

public:
    vector<int> sequentialDigits(int low, int high)
    {
        queue<int> q;
        vector<int> ans;

        for (int num = 1; num < 9; num++)
        {
            q.push(num);
        }

        while (!q.empty())
        {
            int num = q.front();
            q.pop();

            if (isInRange(num, low, high))
            {
                ans.push_back(num);
            }

            int lastDigit = num % 10;
            int nextNum = num * 10 + (lastDigit + 1);

            if (lastDigit == 9 || nextNum > high)
            {
                continue;
            }

            q.push(nextNum);
        }

        return ans;
    }
};

// TC : O(N) where N is number of sequential Digits between low & high
// SC : O(N)

int main()
{

    return 0;
}