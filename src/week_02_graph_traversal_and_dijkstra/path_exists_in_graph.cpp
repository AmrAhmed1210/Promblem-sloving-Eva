#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, int destination, const vector<vector<int>>& adj, vector<bool>& visited)
{
    if (node == destination)
        return true;

    visited[node] = true;

    for (int neighbor : adj[node])
    {
        if (!visited[neighbor] && dfs(neighbor, destination, adj, visited))
            return true;
    }
    return false;
}

bool validPath(int n, const vector<vector<int>>& edges, int source, int destination)
{
    vector<vector<int>> adj(n);
    for (const auto& e : edges)
    {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    vector<bool> visited(n, false);
    return dfs(source, destination, adj, visited);
}

int main()
{
    cout << boolalpha;
    cout << validPath(3, {{0, 1}, {1, 2}, {2, 0}}, 0, 2) << endl;
    cout << validPath(6, {{0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}}, 0, 5) << endl;
}
