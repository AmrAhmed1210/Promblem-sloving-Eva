#include <iostream>
#include <vector>
using namespace std;

long long factorialMemoization(int n, vector<long long>& memo)
{
    if (n <= 1)
        return 1;

    if (memo[n] != -1)
        return memo[n];

    memo[n] = n * factorialMemoization(n - 1, memo);
    return memo[n];
}

long long factorialTabulation(int n)
{
    vector<long long> table(n + 1, 1);

    for (int i = 2; i <= n; i++)
        table[i] = table[i - 1] * i;

    return table[n];
}

int main()
{
    int n = 10;
    vector<long long> memo(n + 1, -1);

    cout << factorialMemoization(n, memo) << endl;
    cout << factorialTabulation(n) << endl;
}
