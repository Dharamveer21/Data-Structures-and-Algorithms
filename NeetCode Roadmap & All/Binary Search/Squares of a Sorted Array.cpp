#include <bits/stdc++.h>
using namespace std;

/*
Approach -- We can use two pointers approach , as we know the square of the negative numbers is also positive
so , if the negative number is smaller even then its square is large , so we use two pointers start & end
square the numbers then put the greater square at the last & move the lower pointer
*/

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int n = nums.size();
        int index = n - 1;

        vector<int> squares(n, 0);
        int start = 0, end = n - 1;

        while (start <= end)
        {
            int startSqaure = (nums[start] * nums[start]);
            int endSqaure = (nums[end] * nums[end]);

            int isInOrder = (startSqaure > endSqaure);

            switch (isInOrder)
            {
            case 0:
                squares[index] = endSqaure;
                end--;
                break;

            case 1:
                squares[index] = startSqaure;
                start++;
                break;
            }

            index--;
        }

        return squares;
    }
};

// TC : O(N)
// SC : O(N)

int main()
{

    return 0;
}