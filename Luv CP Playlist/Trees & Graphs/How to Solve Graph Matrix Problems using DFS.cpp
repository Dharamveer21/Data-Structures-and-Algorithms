#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(vector<vector<int>> &image, int i, int j, int initial_color, int new_color)
    {
        int m = image.size();
        int n = image[0].size();

        if (i < 0 || j < 0)
            return;

        if (i >= m || j >= n)
            return;
        
        if (image[i][j] != initial_color)
            return;

        image[i][j] = new_color;

        dfs(image, i - 1, j, initial_color, new_color);
        dfs(image, i, j - 1, initial_color, new_color);
        dfs(image, i + 1, j, initial_color, new_color);
        dfs(image, i, j + 1, initial_color, new_color);
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int initial_color = image[sr][sc];
        
        if (initial_color == color)
        {
            dfs(image, sr, sc, image[sr][sc], color);
        }
        
        return image;
    }
};

int main()
{

    return 0;
}