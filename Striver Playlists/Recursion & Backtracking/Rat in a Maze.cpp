#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPossible(int x, int y, int n, vector<vector<int>> &grid, vector<vector<bool>> &vis)
    {
        if (x < 0 || y < 0 || x > n - 1 || y > n - 1||grid[x][y] == 0 || vis[x][y] == true)
        {
            return false;
        }

        return true;
    }

    void paths(int i, int j, string &path, vector<vector<bool>> &vis, vector<string> &all_paths, int n, vector<vector<int>> &grid, vector<pair<int, int>> &movements, string &direction)
    {
        if (i == n - 1 && j == n - 1)
        {
            all_paths.push_back(path);
            return;
        }

        // all four directions
        for (int num = 0; num < movements.size(); num++)
        {
            int x = i + movements[num].first;
            int y = j + movements[num].second;

            if (isPossible(x, y, n, grid, vis))
            {
                vis[x][y] = true;
                path.push_back(direction[num]);

                paths(x, y, path, vis, all_paths, n, grid, movements, direction);

                vis[x][y] = false;
                path.pop_back();
            }
        }
    }

    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        string path;
        vector<string> all_paths;

        if (m[0][0] == 0 || m[n - 1][n - 1] == 0)
        {
            return all_paths;
        }

        vector<vector<bool>> visited;
        vector<bool> vis;

        for (int i = 0; i < n; i++)
        {
            vis.push_back(false);
        }

        for (int i = 0; i < n; i++)
        {
            visited.push_back(vis);
        }

        vector<pair<int, int>> movements = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        string direction = "LURD";
        visited[0][0] = true;

        paths(0, 0, path, visited, all_paths, n, m, movements, direction);
        return all_paths;
    }
};

int main()
{

    return 0;
}