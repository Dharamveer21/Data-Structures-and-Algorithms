#include <bits/stdc++.h>
using namespace std;

/*
matrix method -- make a matrix of N * N matrix
*/

int main()
{

    int vertices, edges;
    cin >> vertices >> edges;

    // matrix method
    int adj_matrix[vertices][vertices];

    for (int edge = 0; edge < edges; edge++)
    {
        int vertex1, vertex2;
        cin >> vertex1 >> vertex2;

        adj_matrix[vertex1][vertex2] = 1;
        adj_matrix[vertex2][vertex1] = 1;
    }

    // adjacency list
    vector<int> adj_list[vertices];

    for (int edge = 0; edge < edges; edge++)
    {
        int vertex1, vertex2;
        cin >> vertex1 >> vertex2;

        adj_list[vertex1].push_back(vertex2);
        adj_list[vertex2].push_back(vertex1);
    }

    return 0;
}