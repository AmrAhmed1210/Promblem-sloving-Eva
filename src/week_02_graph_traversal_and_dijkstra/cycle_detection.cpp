#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, int parent, const vector<vector<int>>& adj, vector<bool>& visited)
{
    visited[node] = true;

    for (int neighbor : adj[node])
    {
        if (!visited[neighbor])
        {
            if (dfs(neighbor, node, adj, visited))
                return true;
        }
        else if (neighbor != parent)
        {
            return true;
        }
    }
    return false;
}

bool hasCycle(int n, const vector<vector<int>>& edges)
{
    vector<vector<int>> adj(n);
    for (const auto& e : edges)
    {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    vector<bool> visited(n, false);
    for (int node = 0; node < n; node++)
    {
        if (!visited[node] && dfs(node, -1, adj, visited))
            return true;
    }
    return false;
}

int main()
{
    cout << boolalpha;
    cout << hasCycle(6, {{0, 1}, {0, 2}, {3, 4}, {4, 5}, {3, 5}}) << endl;
    cout << hasCycle(4, {{0, 1}, {1, 2}, {2, 3}}) << endl;
}
