#include <bits/stdc++.h>
using namespace std;

/*
Approach 1 -- Store the prefixProduct & Suffix Product in two arrays & calculate the prefix & suffix Product
Finally for each index mutiply prefixProd & suffixProd to get the answer . Return the answer array .

Approach 2 -- Get the product of the whole array except the zeros . Also countNumber of zeros . If Number of
Zeros are 0 then just divide the whole product array with current num & store it for each num in the array .
If the number of Zeros are 1 then put whole product at the index of zero all other positions put 0 .
If the number of Zeros are greater than 1 then put 0 at all the indexes of the answer array .
*/

// Approach 1
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> productOfAllNumbersExceptSelf(n);
        int *prefixProduct = new int[n], *suffixProduct = new int[n];

        for (int ind = 0; ind < n; ind++)
        {
            int prefixInd = ind, suffixInd = n - ind - 1;
            int prefixNum = nums[prefixInd], suffixNum = nums[suffixInd];

            prefixProduct[prefixInd] = (((prefixInd == 0) ? 1 : prefixProduct[prefixInd - 1]) * prefixNum);
            suffixProduct[suffixInd] = (((suffixInd == n - 1) ? 1 : suffixProduct[suffixInd + 1]) * suffixNum);
        }

        for (int ind = 0; ind < n; ind++)
        {
            int prefixInd = ind - 1, suffixInd = ind + 1;

            int prefixProd = ((prefixInd == -1) ? 1 : prefixProduct[prefixInd]);
            int suffixProd = ((suffixInd == n) ? 1 : suffixProduct[suffixInd]);

            productOfAllNumbersExceptSelf[ind] = prefixProd * suffixProd;
        }

        delete[] prefixProduct, suffixProduct;
        return productOfAllNumbersExceptSelf;
    }
};

// TC : O(N)
// SC : O(N)

// Approach 2
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size(), productOfAllNumbers = 1;
        vector<int> productOfAllNumbersExceptSelf(n, 0);
        int countNumberOfZeros = 0, indexOfOnlyZero = -1;

        for (int ind = 0; ind < n; ind++)
        {
            int num = nums[ind];

            if (num == 0)
            {
                indexOfOnlyZero = ind;
                countNumberOfZeros++;
                continue;
            }

            productOfAllNumbers = productOfAllNumbers * num;
        }

        switch (countNumberOfZeros)
        {
        case 1:
            productOfAllNumbersExceptSelf[indexOfOnlyZero] = productOfAllNumbers;
            break;

        case 0:
            for (int ind = 0; ind < n; ind++)
            {
                int num = nums[ind];
                int val = (productOfAllNumbers / num);

                productOfAllNumbersExceptSelf[ind] = val;
            }
        }

        return productOfAllNumbersExceptSelf;
    }
};

// TC : O(N)
// SC : O(1)

int main()
{

    return 0;
}