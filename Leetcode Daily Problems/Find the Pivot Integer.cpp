#include <bits/stdc++.h>
using namespace std;

/*
Approach -- We can use many approaches in this problem like simple maths equation which is x^2 = (n*(n+1))/2 .
We can also use two pointers to get the sum from both ends & increase it until they become equal .
We can also use binary search in this problem as we find if pivot^2 == (n) * (n+1)/2 . If it is equal then it
is our pivot number but if pivot square is less then we will increase lo to mid+1 else hi to mid - 1 .
*/

// Maths Approach
class Solution
{
public:
    int pivotInteger(int n)
    {
        int totalSum = ((n * (n + 1)) / 2);
        int pivot = sqrt(totalSum);

        return ((pivot * pivot == totalSum) ? pivot : -1);
    }
};

// TC : O(1)
// SC : O(1)

// Two Pointers Approach
class Solution
{
public:
    int pivotInteger(int n)
    {
        int pivotNumber = -1;
        int leftNum = 1, rightNum = n;
        int leftSum = 1, rightSum = n;

        while (leftNum <= rightNum)
        {
            int leftAndRightSumComparison = (leftSum >= rightSum) + (leftSum == rightSum);

            switch (leftAndRightSumComparison)
            {
            case 0:
                leftNum = leftNum + 1;
                leftSum = leftSum + leftNum;
                break;

            case 1:
                rightNum = rightNum - 1;
                rightSum = rightSum + rightNum;
                break;

            case 2:
                if (leftNum == rightNum)
                {
                    pivotNumber = leftNum;
                    return pivotNumber;
                }

                leftNum = leftNum + 1;
                leftSum = leftSum + leftNum;

                rightNum = rightNum - 1;
                rightSum = rightSum + rightNum;
            }
        }

        return pivotNumber;
    }
};

// TC : O(N)
// SC : O(1)

// Binary Search Approach
class Solution
{
public:
    int pivotInteger(int n)
    {
        int totalSum = ((n * (n + 1)) / 2);
        int lo = 1, hi = n, pivotNumber = -1;

        while (lo <= hi)
        {
            int mid = (lo + hi) >> 1;
            int pivotSquare = mid * mid;

            int pivotAndTotalSumComparison = (pivotSquare >= totalSum) + (pivotSquare == totalSum);

            switch (pivotAndTotalSumComparison)
            {
            case 0:
                lo = mid + 1;
                break;

            case 1:
                hi = mid - 1;
                break;

            case 2:
                pivotNumber = mid;
                return pivotNumber;
            }
        }

        return pivotNumber;
    }
};

// TC : O(log(N))
// SC : O(1)

int main()
{

    return 0;
}