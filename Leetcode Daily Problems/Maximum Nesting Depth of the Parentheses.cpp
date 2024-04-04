#include <bits/stdc++.h>
using namespace std;

/*
Approach 1 -- We just need to keep the count of the pair of nested brackets and return the maximum count so , we
can use stack whenever we got a open bracket we put it in the stack and when we get a close bracket we can pop
out open bracket from the stack , Now the maximum size of the stack in all times is the max nested depth of VPS.

Approach 2 -- We just need to keep the maxCount of open bracket at a time so we can use a depth count variable
whenever we find the open bracket we can increase count by 1 and when we find a close bracket decrease the
count by 1 . The maximum value of count among all its values at all times is the max nested Depth of the VPS.
*/

// Approach 1
class Solution
{
public:
    int maxDepth(string &s)
    {
        int n = s.size(), maxDepthOfVPS = 0;
        stack<char> amountOfOpenBrackets;

        for (int ind = 0; ind < n; ind++)
        {
            char ch = s[ind];

            switch (ch)
            {
            case '(':
                amountOfOpenBrackets.push(ch);
                break;

            case ')':
                amountOfOpenBrackets.pop();
            }

            int currDepthOfVPS = amountOfOpenBrackets.size();
            maxDepthOfVPS = max(maxDepthOfVPS, currDepthOfVPS);
        }

        return maxDepthOfVPS;
    }
};

// TC : O(N) -- traversing the all char of the string
// SC : O(N/2) = O(N) -- max open bracksts can be (n/2)

// Approach 2
class Solution
{
public:
    int maxDepth(string &s)
    {
        int n = s.size(), maxDepthOfVPS = 0, currDepthOfVPS = 0;

        for (int ind = 0; ind < n; ind++)
        {
            char ch = s[ind];

            switch (ch)
            {
            case '(':
                currDepthOfVPS++;
                break;

            case ')':
                currDepthOfVPS--;
            }

            maxDepthOfVPS = max(maxDepthOfVPS, currDepthOfVPS);
        }

        return maxDepthOfVPS;
    }
};

// TC : O(N)
// SC : O(1)

int main()
{

    return 0;
}