#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> buildAdjacencyMatrix(int n, const vector<pair<int, int>>& edges, bool directed)
{
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    for (const auto& [u, v] : edges)
    {
        matrix[u][v] = 1;
        if (!directed)
            matrix[v][u] = 1;
    }
    return matrix;
}

int main()
{
    vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {1, 3}};
    vector<vector<int>> matrix = buildAdjacencyMatrix(4, edges, false);

    for (const auto& row : matrix)
    {
        for (int cell : row)
            cout << cell << " ";
        cout << endl;
    }
}
