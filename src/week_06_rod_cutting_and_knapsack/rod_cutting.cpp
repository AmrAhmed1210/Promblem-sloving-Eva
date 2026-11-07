#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int rodCutting(const vector<int>& prices, int rodLength)
{
    vector<int> best(rodLength + 1, 0);

    for (int length = 1; length <= rodLength; length++)
    {
        for (int cut = 1; cut <= length; cut++)
            best[length] = max(best[length], prices[cut - 1] + best[length - cut]);
    }
    return best[rodLength];
}

int main()
{
    vector<int> prices = {1, 5, 8, 9, 10, 17, 17, 20};

    cout << rodCutting(prices, 8) << endl;
    cout << rodCutting(prices, 4) << endl;
}
