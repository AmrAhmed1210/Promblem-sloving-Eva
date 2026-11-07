#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> bfs(int start, const vector<vector<int>>& adj)
{
    vector<int> order;
    vector<bool> visited(adj.size(), false);
    queue<int> pending;

    visited[start] = true;
    pending.push(start);

    while (!pending.empty())
    {
        int node = pending.front();
        pending.pop();
        order.push_back(node);

        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                pending.push(neighbor);
            }
        }
    }
    return order;
}

int main()
{
    vector<vector<int>> adj = {{1, 2}, {0, 3, 6}, {0, 4, 5}, {1}, {2}, {2}, {1}};

    cout << "BFS:";
    for (int node : bfs(0, adj))
        cout << " " << node;
    cout << endl;
}
