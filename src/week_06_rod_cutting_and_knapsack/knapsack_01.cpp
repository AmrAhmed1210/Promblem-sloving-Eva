#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int knapsack(int capacity, const vector<int>& weights, const vector<int>& profits, int index, vector<vector<int>>& memo)
{
    if (index < 0)
        return 0;

    if (memo[index][capacity] != -1)
        return memo[index][capacity];

    int skip = knapsack(capacity, weights, profits, index - 1, memo);

    if (weights[index] > capacity)
        return memo[index][capacity] = skip;

    int take = profits[index] + knapsack(capacity - weights[index], weights, profits, index - 1, memo);
    return memo[index][capacity] = max(take, skip);
}

int main()
{
    vector<int> profits = {60, 100, 120};
    vector<int> weights = {1, 3, 5};
    int capacity = 5;
    int n = weights.size();

    vector<vector<int>> memo(n, vector<int>(capacity + 1, -1));

    cout << knapsack(capacity, weights, profits, n - 1, memo) << endl;
}
