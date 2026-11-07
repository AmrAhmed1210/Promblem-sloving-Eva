#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = INT_MAX / 2;

using Graph = vector<vector<pair<int, int>>>;

void addEdge(Graph& graph, int from, int to, int weight, bool directed)
{
    graph[from].push_back({to, weight});
    if (!directed)
        graph[to].push_back({from, weight});
}

vector<int> dijkstra(const Graph& graph, int start)
{
    vector<int> distance(graph.size(), INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> queue;

    distance[start] = 0;
    queue.push({0, start});

    while (!queue.empty())
    {
        auto [dist, node] = queue.top();
        queue.pop();

        if (dist > distance[node])
            continue;

        for (const auto& [next, weight] : graph[node])
        {
            if (dist + weight < distance[next])
            {
                distance[next] = dist + weight;
                queue.push({distance[next], next});
            }
        }
    }
    return distance;
}

int main()
{
    Graph graph(5);
    addEdge(graph, 0, 1, 4, false);
    addEdge(graph, 0, 2, 1, false);
    addEdge(graph, 2, 1, 2, false);
    addEdge(graph, 1, 3, 1, false);
    addEdge(graph, 2, 3, 5, false);

    vector<int> distance = dijkstra(graph, 0);

    for (size_t node = 0; node < distance.size(); node++)
    {
        cout << "0 -> " << node << " : ";
        if (distance[node] == INF)
            cout << "unreachable" << endl;
        else
            cout << distance[node] << endl;
    }
}
