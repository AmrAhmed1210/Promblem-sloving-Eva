#include <iostream>
#include <vector>
using namespace std;

long long fibonacciMemoization(int n, vector<long long>& memo)
{
    if (n <= 1)
        return n;

    if (memo[n] != -1)
        return memo[n];

    memo[n] = fibonacciMemoization(n - 1, memo) + fibonacciMemoization(n - 2, memo);
    return memo[n];
}

long long fibonacciTabulation(int n)
{
    if (n <= 1)
        return n;

    vector<long long> table(n + 1);
    table[0] = 0;
    table[1] = 1;

    for (int i = 2; i <= n; i++)
        table[i] = table[i - 1] + table[i - 2];

    return table[n];
}

int main()
{
    int n = 50;
    vector<long long> memo(n + 1, -1);

    cout << fibonacciMemoization(n, memo) << endl;
    cout << fibonacciTabulation(n) << endl;
}
