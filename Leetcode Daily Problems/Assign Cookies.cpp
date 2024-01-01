#include <bits/stdc++.h>
using namespace std;

/*
Approach -- Here we need to maximase the number of satisfied children , so we need to start giving cookies to
children having minimum greed , so we can cover as many children as possible , hence we sort greed array

Now, if we need to give the children the cookies , we will try to give the cookie with minimum size possible to
satisfy the child , so we can use bigger cookies for some more greedy child . Hence we sort cookie size array

Finally we use two pointer approach to traverse simantenously the both array to assign cookies to children
Whenever any one get out of bound the answer is count of children
*/

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        int n1 = g.size(), n2 = s.size();
        int satisfiedChildCount = 0;
        int child = 0, cookie = 0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        while (child < n1 && cookie < n2)
        {
            int childGreed = g[child];
            int cookieSize = s[cookie];

            if (childGreed <= cookieSize)
            {
                child++;
                cookie++;
                satisfiedChildCount++;
            }

            else
            {
                cookie++;
            }
        }

        return satisfiedChildCount;
    }
};

// TC : O(N * log(N) + N)  = O(N * log(N)) -- sorting + traversing
// SC : O(log(N)) -- space used during sorting

int main()
{

    return 0;
}