#include <bits/stdc++.h>
using namespace std;

int getKthLargest(vector<int> &arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> subarrSum;
    int subarrCnt = k;

    for (int ind1 = 0; ind1 < arr.size(); ind1++)
    {
        int sum = 0;

        for (int ind2 = ind1; ind2 < arr.size(); ind2++)
        {
            sum += arr[ind2];
               
            if (subarrCnt != 0)
            {
                subarrSum.push(sum);
                subarrCnt--;
                continue;
            }
              
            int currSum = sum;
            int topSum = subarrSum.top();

            if (topSum < currSum)
            {
                subarrSum.pop();
                subarrSum.push(currSum);
            }
        }
    }

    int kthLargestSum = subarrSum.top();
    return kthLargestSum;
}

int main()
{

    return 0;
}