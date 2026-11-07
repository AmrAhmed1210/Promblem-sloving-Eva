#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

vector<int> minCoins(vector<int> coins, int amount)
{
    sort(coins.begin(), coins.end(), greater<int>());

    vector<int> used;
    for (int coin : coins)
    {
        while (amount >= coin)
        {
            amount -= coin;
            used.push_back(coin);
        }
    }
    return used;
}

int main()
{
    vector<int> used = minCoins({1, 5, 10, 25, 50}, 68);

    cout << "Coins used:";
    for (int coin : used)
        cout << " " << coin;
    cout << endl;
}
