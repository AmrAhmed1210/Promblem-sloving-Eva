#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, const vector<vector<int>>& adj, vector<bool>& visited, vector<int>& order)
{
    visited[node] = true;
    order.push_back(node);

    for (int neighbor : adj[node])
    {
        if (!visited[neighbor])
            dfs(neighbor, adj, visited, order);
    }
}

int main()
{
    vector<vector<int>> adj = {{1, 2}, {0, 3}, {0, 4}, {1}, {2}};
    vector<bool> visited(adj.size(), false);
    vector<int> order;

    dfs(0, adj, visited, order);

    cout << "DFS:";
    for (int node : order)
        cout << " " << node;
    cout << endl;
}
