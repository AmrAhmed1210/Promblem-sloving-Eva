#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int height(int node, int parent, const vector<vector<int>>& adj, int& diameter)
{
    int longest = 0;
    int secondLongest = 0;

    for (int neighbor : adj[node])
    {
        if (neighbor == parent)
            continue;

        int h = height(neighbor, node, adj, diameter) + 1;
        if (h > longest)
        {
            secondLongest = longest;
            longest = h;
        }
        else if (h > secondLongest)
        {
            secondLongest = h;
        }
    }

    diameter = max(diameter, longest + secondLongest);
    return longest;
}

int treeDiameter(const vector<int>& parents)
{
    int n = parents.size();
    vector<vector<int>> adj(n);
    int root = 0;

    for (int i = 0; i < n; i++)
    {
        if (parents[i] == -1)
        {
            root = i;
        }
        else
        {
            adj[i].push_back(parents[i]);
            adj[parents[i]].push_back(i);
        }
    }

    int diameter = 0;
    height(root, -1, adj, diameter);
    return diameter;
}

int main()
{
    cout << treeDiameter({-1, 0, 0, 0, 3}) << endl;
    cout << treeDiameter({-1, 0, 1, 2}) << endl;
}
