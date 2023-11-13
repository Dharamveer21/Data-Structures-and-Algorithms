#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findTheWinner(int n, int k)
    {
        vector<int> v;

        for (int i = 0; i < n; i++)
        {
            v.push_back(i + 1);
        }

        int index = 0;
        k--;

        while (v.size() > 1)
        {
            index = ((index + k) % (v.size()));
            v.erase(v.begin() + index);
        }

        return v[0];
    }
};

int main()
{

    return 0;
}