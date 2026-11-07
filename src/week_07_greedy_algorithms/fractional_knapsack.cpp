#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Item
{
    int weight;
    int profit;
};

double fractionalKnapsack(int capacity, vector<Item> items)
{
    sort(items.begin(), items.end(), [](const Item& a, const Item& b)
    {
        return static_cast<double>(a.profit) / a.weight > static_cast<double>(b.profit) / b.weight;
    });

    double total = 0;

    for (const Item& item : items)
    {
        if (capacity >= item.weight)
        {
            total += item.profit;
            capacity -= item.weight;
        }
        else
        {
            total += static_cast<double>(item.profit) * capacity / item.weight;
            break;
        }
    }
    return total;
}

int main()
{
    vector<Item> items = {{10, 60}, {20, 100}, {30, 120}};

    cout << fractionalKnapsack(50, items) << endl;
}
