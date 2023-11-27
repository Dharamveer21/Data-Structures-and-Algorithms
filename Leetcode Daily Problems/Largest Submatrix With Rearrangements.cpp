#include <bits/stdc++.h>
using namespace std;

/*
Approach -- we will use each row as the base & calculate the area of largest rectangle having base on that row
now for each row we have certain buildings whose size is determined by the length of consecutive 1s upto this row for that column
if there is 0 in this row & col then length of building is 0 , we will find the lengths of buildings for each row in this way
now we have to calculate largest common area of these buildings for each row , we can rearrange columns , we will sort each row
Now in the sorted rows we can easily find the area , first element is shortest so it have common with all elements after it
in this way for each element we multiply height of building with length of row after it till end & find maxArea
*/

class Solution
{
public:
    int largestSubmatrix(vector<vector<int>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int maxAreaMatrix1 = 0;
    
        vector<vector<int>> consecutiveMatrix1(rows, vector<int>(cols, 0));
    
        for (int col = 0; col < cols; col++)
        {
            consecutiveMatrix1[0][col] = matrix[0][col];
        }
    
        for (int row = 1; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                int currElement = matrix[row][col];
    
                if (currElement)
                {
                    consecutiveMatrix1[row][col] = consecutiveMatrix1[row - 1][col] + 1;
                }
    
                else
                {
                    consecutiveMatrix1[row][col] = 0;
                }
            }
        }
    
        for (int row = 0; row < rows; row++)
        {
            sort(consecutiveMatrix1[row].begin(), consecutiveMatrix1[row].end());
    
            int maxAreaRow1 = 0;
    
            for (int col = 0; col < cols; col++)
            {
                int length = cols - col;
                int height = consecutiveMatrix1[row][col];
    
                int maxAreaCol1 = length * height;
                maxAreaRow1 = max(maxAreaRow1, maxAreaCol1);
            }
    
            maxAreaMatrix1 = max(maxAreaMatrix1, maxAreaRow1);
        }
    
        return maxAreaMatrix1;
    }
};

// m -- rows , n -- cols
// TC : O(m * n + m * n * log(n)) = O(m * n * log(n))
// SC : O(m * n)

int main()
{

    return 0;
}