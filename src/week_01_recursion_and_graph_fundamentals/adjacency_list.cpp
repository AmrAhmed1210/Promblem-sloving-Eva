#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> buildAdjacencyList(int n, const vector<pair<int, int>>& edges, bool directed)
{
    vector<vector<int>> adj(n);
    for (const auto& [u, v] : edges)
    {
        adj[u].push_back(v);
        if (!directed)
            adj[v].push_back(u);
    }
    return adj;
}

int main()
{
    vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {1, 3}};
    vector<vector<int>> adj = buildAdjacencyList(4, edges, false);

    for (int node = 0; node < 4; node++)
    {
        cout << node << " ->";
        for (int neighbor : adj[node])
            cout << " " << neighbor;
        cout << endl;
    }
}
