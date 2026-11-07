#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

void explore(int city, const vector<vector<pair<int, int>>>& adj, vector<bool>& visited, int& minScore)
{
    visited[city] = true;

    for (const auto& [next, distance] : adj[city])
    {
        minScore = min(minScore, distance);
        if (!visited[next])
            explore(next, adj, visited, minScore);
    }
}

int minScore(int n, const vector<vector<int>>& roads)
{
    vector<vector<pair<int, int>>> adj(n + 1);
    for (const auto& road : roads)
    {
        adj[road[0]].push_back({road[1], road[2]});
        adj[road[1]].push_back({road[0], road[2]});
    }

    vector<bool> visited(n + 1, false);
    int result = INT_MAX;
    explore(1, adj, visited, result);
    return result;
}

int main()
{
    cout << minScore(4, {{1, 2, 9}, {2, 3, 6}, {2, 4, 5}, {1, 4, 7}}) << endl;
    cout << minScore(4, {{1, 2, 2}, {1, 3, 4}, {3, 4, 7}}) << endl;
}
