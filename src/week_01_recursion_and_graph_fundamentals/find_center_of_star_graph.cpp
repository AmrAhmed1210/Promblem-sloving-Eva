#include <iostream>
#include <vector>
using namespace std;

int findCenter(const vector<vector<int>>& edges)
{
    int a = edges[0][0];
    int b = edges[0][1];

    if (a == edges[1][0] || a == edges[1][1])
        return a;
    return b;
}

int main()
{
    vector<vector<int>> first = {{1, 2}, {2, 3}, {4, 2}};
    vector<vector<int>> second = {{1, 2}, {5, 1}, {1, 3}, {1, 4}};

    cout << findCenter(first) << endl;
    cout << findCenter(second) << endl;
}
