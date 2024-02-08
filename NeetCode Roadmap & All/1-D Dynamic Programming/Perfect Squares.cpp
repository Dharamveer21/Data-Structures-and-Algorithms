#include <bits/stdc++.h>
using namespace std;

/*
Approach -- It is a DP Problem we have to try all ways . For any number n we can find all possible ways to make
it using the squares & get the minimum number of squares for making that number . So, Consider a function f :-
f(num) -- gives us the minimum number of squares to get sum as the given number . So , we can say that :-
f(num) = min(f(num - 1) , f(num - 4) , f(num - 9) .....) + 1 , it is divided into subproblems .
*/

class Solution
{
protected:
    // memoisation
    int numOfSquaresSum(int num, vector<int> &minSquaresNum)
    {
        if (minSquaresNum[num] != -1)
        {
            return minSquaresNum[num];
        }

        int minSquaresToGetNum = num;

        for (int ind = 1; ind * ind <= num; ind++)
        {
            int square = ind * ind;
            int remainingNumber = num - square;
            int squaresToGetNum = numOfSquaresSum(remainingNumber, minSquaresNum) + 1;

            minSquaresToGetNum = min(minSquaresToGetNum, squaresToGetNum);
        }

        return minSquaresNum[num] = minSquaresToGetNum;
    }

public:
    int numSquares(int n)
    {
        vector<int> minSquaresNum(n + 1, -1);
        minSquaresNum[0] = 0;

        int minSquaresToGetNum = numOfSquaresSum(n, minSquaresNum);
        return minSquaresToGetNum;
    }

    // tabulation
    int numSquares(int n)
    {
        vector<int> minSquaresNum(n + 1, 0);

        for (int num = 1; num <= n; num++)
        {
            int minSquaresToGetNum = num;

            for (int ind = 1; ind * ind <= num; ind++)
            {
                int square = ind * ind;
                int remainingNumber = num - square;
                int squaresToGetNum = minSquaresNum[remainingNumber] + 1;

                minSquaresToGetNum = min(minSquaresToGetNum, squaresToGetNum);
            }

            minSquaresNum[num] = minSquaresToGetNum;
        }

        int minSquaresToGetNum = minSquaresNum[n];
        return minSquaresToGetNum;
    }
};

// TC : O(N * sqrt(N))
// SC : O(N)

int main()
{

    return 0;
}