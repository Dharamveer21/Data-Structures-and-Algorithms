#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K)
{
    queue<int> q;
    vector<long long> ans;
    int prev = 0;
    int curr;

    // insert the first window
    for (int index = 0; index < K; index++)
    {
        int val = A[index];

        if (val < 0)
        {
            q.push(index);
        }
    }

    if (q.empty())
    {
        ans.push_back(0);
    }

    else
    {
        int ind = q.front();
        ans.push_back(A[ind]);
    }

    // for other windows
    for (int index = K; index <= N - 1; index++)
    {
        curr = index;

        if (A[prev] < 0)
        {
            q.pop();
        }

        int val = A[curr];

        if (val < 0)
        {
            q.push(curr);
        }

        if (q.empty())
        {
            ans.push_back(0);
        }

        else
        {
            int ind = q.front();
            ans.push_back(A[ind]);
        }

        prev++;
    }

    return ans;
}

int main()
{

    return 0;
}