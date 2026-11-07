#include <iostream>
#include <vector>
using namespace std;

struct Edge
{
    int from;
    int to;
    int weight;
};

vector<Edge> buildEdgeList(const vector<vector<int>>& input)
{
    vector<Edge> edges;
    for (const auto& e : input)
        edges.push_back({e[0], e[1], e[2]});
    return edges;
}

int main()
{
    vector<Edge> edges = buildEdgeList({{0, 1, 4}, {0, 2, 1}, {1, 3, 2}});

    for (const Edge& e : edges)
        cout << e.from << " -> " << e.to << " (weight " << e.weight << ")" << endl;
}
