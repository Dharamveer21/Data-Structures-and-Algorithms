#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.

    bool isPossible(int colour, int node, vector<int> &colour_of_node, bool graph[101][101])
    {
        for (int i = 0; i < 101; i++)
        {
            if (graph[node][i] && colour_of_node[i] == colour)
            {
                return false;
            }
        }

        return true;
    }

    bool colouring(int node, bool graph[101][101], vector<int> &colour_of_node, int m, int n)
    {
        if (node == n)
        {
            return true;
        }
        
        for (int colour = 0; colour < m; colour++)
        {
            if (node != 0)
            {
                if (isPossible(colour, node, colour_of_node, graph))
                {
                    colour_of_node[node] = colour;

                    if (colouring(node + 1, graph, colour_of_node, m, n))
                    {
                        return true;
                    }

                    colour_of_node[node] = -1;
                }
            }

            else
            {
                colour_of_node[node] = colour;

                if (colouring(node + 1, graph, colour_of_node, m, n))
                {
                    return true;
                }

                colour_of_node[node] = -1;
            }
        }

        return false;
    }

    bool graphColoring(bool graph[101][101], int m, int n)
    {
        vector<int> colour_of_node(n, -1);
        bool ans = colouring(0, graph, colour_of_node, m, n);
        return ans;
    }
};

int main()
{

    return 0;
}
