#include <bits/stdc++.h>
using namespace std;

/*
Approach -- all the elements on diagonals have equal value for row + col
now we have to just sort the array in order of row+col from min to max
now the numbers which have same value for (row+col) among them the values which has lower values of col comes first
hence we intern both (row+col) , col in priority queue(min heap) with the corresponding value
*/

class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &nums)
    {
        priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> diagonals;
        vector<int> diagonal_order;

        for (int row = 0; row < nums.size(); row++)
        {
            for (int col = 0; col < nums[row].size(); col++)
            {
                int position = row + col;
                int rank = col;
                int num = nums[row][col];

                diagonals.push({{position, rank}, num});
            }
        }

        while (!diagonals.empty())
        {
            auto val = diagonals.top();
            diagonals.pop();

            int num = val.second;
            diagonal_order.push_back(num);
        }

        return diagonal_order;
    }
};

// TC : O(N*M + N*M) = O(N*M)
// SC : O(N*M + N*M) = O(N*M)

int main()
{

    return 0;
}
