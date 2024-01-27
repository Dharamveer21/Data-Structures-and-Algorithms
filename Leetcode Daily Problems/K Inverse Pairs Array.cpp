#include <bits/stdc++.h>
using namespace std;

/*
Approach -- here we can see a particular observation , if in an array which contains elements from 1 to n-1
lets say there are "p" number of inversions in this array then if we want to increase the number of inversions
we can put the new number "n" at different positions according to need

Consider 1 based indexing :-

if we put n at index 'n'   -- 1 2 3 4 ... n-1 n ,               it will increase inversion count by 0
if we put n at index 'n-1' -- 1 2 3 4 ... n n-1 ,               it will increase inversion count by 1
if we put n at index 'n-2' -- 1 2 3 4 ... n n-2 n-1 ,           it will increase inversion count by 2
if we put n at index 'n-3' -- 1 2 3 4 ... n n-3 n-2 n-1 ,       it will increase inversion count by 3
if we put n at index 'n-k' -- 1 2 3 4 ... n n-k ... n-2 n-1 ,   it will increase inversion count by k
if we put n at index '1'   -- n 1 2 3 ... n-5 n-4 n-3 n-2 n-1 , it will increase inversion count by n-1

we can increase the inversion count by 0 to (n-1) in array of size (n-1) consisting of numbers from 1 to (n-1)
so we can make a recurence relation as -: a function which will tell us number of arrays having two parameters
as (n,k) -- n -> array len & k -> required inversion count

Here is the base case:- if k == 0 then there is only 1 array possible which is sorted one of any length

f(n,k) = f(n-1,k) + f(n-1,k-1) + f(n-1,k-2) .... f(n-1,max(k-(n-1),0))
then apply memoisation --> tabulation --> space optimization --> optimal space optimization
*/

class Solution
{
private:
    static const int M = 1e9 + 7;

protected:
    // memoisation
    int findNumArraysWithInversionsCount(int arrLen, int inversions, vector<vector<int>> &arrayCount)
    {
        if (inversions == 0)
        {
            return 1;
        }

        if (arrayCount[arrLen][inversions] != -1)
        {
            return arrayCount[arrLen][inversions];
        }

        int totalInversions = 0;

        for (int ind = arrLen; ind >= max(arrLen - inversions, 1); ind--)
        {
            int inversionByAddInd = arrLen - ind;
            int inversionCountLeft = inversions - inversionByAddInd;

            int numArrays = findNumArraysWithInversionsCount(arrLen - 1, inversionCountLeft, arrayCount);
            totalInversions = (totalInversions + 0LL + numArrays) % M;
        }

        return arrayCount[arrLen][inversions] = totalInversions;
    }

public:
    int kInversePairs(int n, int k)
    {
        vector<vector<int>> arrayCount(n + 1, vector<int>(k + 1, -1));

        int numArraysWithInversionsCount = findNumArraysWithInversionsCount(n, k, arrayCount);
        return numArraysWithInversionsCount;
    }

    // tabulation
    int kInversePairs(int n, int k)
    {
        vector<vector<int>> arrayCount(n + 1, vector<int>(k + 1, 0));
        arrayCount[1][0] = 1;

        for (int arrLen = 2; arrLen <= n; arrLen++)
        {
            for (int inversions = 0; inversions <= k; inversions++)
            {
                int totalInversions = 0;

                for (int ind = arrLen; ind >= max(arrLen - inversions, 1); ind--)
                {
                    int inversionByAddInd = arrLen - ind;
                    int inversionCountLeft = inversions - inversionByAddInd;

                    int numArrays = arrayCount[arrLen - 1][inversionCountLeft];
                    totalInversions = (totalInversions + 0LL + numArrays) % M;
                }

                arrayCount[arrLen][inversions] = totalInversions;
            }
        }

        int numArraysWithInversionsCount = arrayCount[n][k];
        return numArraysWithInversionsCount;
    }

    // space optimization
    int kInversePairs(int n, int k)
    {
        vector<int> prevArrayCount(k + 1, 0);
        vector<int> currArrayCount(k + 1, 0);

        prevArrayCount[0] = 1;
        currArrayCount[0] = 1;

        for (int arrLen = 2; arrLen <= n; arrLen++)
        {
            for (int inversions = 0; inversions <= k; inversions++)
            {
                int totalInversions = 0;

                // it is actually the cumulative sum of the above row upto index == inversions
                // the len of elements who cumulative sum is to be taken must be equal to arrLen from last

                for (int ind = arrLen; ind >= max(arrLen - inversions, 1); ind--)
                {
                    int inversionByAddInd = arrLen - ind;
                    int inversionCountLeft = inversions - inversionByAddInd;

                    int numArrays = prevArrayCount[inversionCountLeft];
                    totalInversions = (totalInversions + 0LL + numArrays) % M;
                }

                currArrayCount[inversions] = totalInversions;
            }

            for (int inversions = 0; inversions <= k; inversions++)
            {
                prevArrayCount[inversions] = currArrayCount[inversions];
            }
        }

        int numArraysWithInversionsCount = currArrayCount[k];
        return numArraysWithInversionsCount;
    }

    // optimal space optimization
    int kInversePairs(int n, int k)
    {
        vector<int> prevArrayCount(k + 1, 0);
        vector<int> currArrayCount(k + 1, 0);

        prevArrayCount[0] = 1;
        currArrayCount[0] = 1;

        for (int arrLen = 2; arrLen <= n; arrLen++)
        {
            int numArraysForPreviousLen = 0;

            for (int inversions = 0; inversions <= k; inversions++)
            {
                if (inversions >= arrLen)
                {
                    int removeInd = inversions - arrLen;
                    numArraysForPreviousLen = (numArraysForPreviousLen + 0LL - prevArrayCount[removeInd] + M) % M;
                }

                numArraysForPreviousLen = (numArraysForPreviousLen + 0LL + prevArrayCount[inversions]) % M;
                currArrayCount[inversions] = numArraysForPreviousLen;
            }

            for (int inversions = 0; inversions <= k; inversions++)
            {
                prevArrayCount[inversions] = currArrayCount[inversions];
            }
        }

        int numArraysWithInversionsCount = currArrayCount[k];
        return numArraysWithInversionsCount;
    }
};

// TC : O(N * K)
// SC : O(K)

int main()
{

    return 0;
}