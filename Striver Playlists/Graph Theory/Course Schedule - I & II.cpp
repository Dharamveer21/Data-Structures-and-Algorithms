#include <bits/stdc++.h>
using namespace std;

//Course Schedule I
class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> graph[numCourses];
        vector<int> indegree(numCourses, 0);
        int course_cnt = 0;

        for (int i = 0; i < prerequisites.size(); i++)
        {
            int par = prerequisites[i][1];
            int child = prerequisites[i][0];

            graph[par].push_back(child);
            indegree[child]++;
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            course_cnt++;

            for (int child : graph[node])
            {
                indegree[child]--;

                if (indegree[child] == 0)
                {
                    q.push(child);
                }
            }
        }

        return (numCourses == course_cnt);
    }
};

// Course Schedule II
class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> graph[numCourses];
        vector<int> indegree(numCourses, 0);
        vector<int> ans;

        for (int i = 0; i < prerequisites.size(); i++)
        {
            int par = prerequisites[i][1];
            int child = prerequisites[i][0];

            graph[par].push_back(child);
            indegree[child]++;
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for (int child : graph[node])
            {
                indegree[child]--;

                if (indegree[child] == 0)
                {
                    q.push(child);
                }
            }
        }

        if (ans.size() == numCourses)
        {
            return ans;
        }

        ans.clear();
        return ans;
    }
};

int main()
{

    return 0;
}