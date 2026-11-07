#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void search(const vector<int>& candidates, size_t start, int remaining, vector<int>& current, vector<vector<int>>& result)
{
    if (remaining == 0)
    {
        result.push_back(current);
        return;
    }

    for (size_t i = start; i < candidates.size(); i++)
    {
        if (candidates[i] > remaining)
            break;

        current.push_back(candidates[i]);
        search(candidates, i, remaining - candidates[i], current, result);
        current.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> candidates, int target)
{
    sort(candidates.begin(), candidates.end());

    vector<vector<int>> result;
    vector<int> current;
    search(candidates, 0, target, current, result);
    return result;
}

int main()
{
    for (const auto& combination : combinationSum({2, 3, 6, 7}, 7))
    {
        for (int value : combination)
            cout << value << " ";
        cout << endl;
    }

    cout << "--" << endl;

    for (const auto& combination : combinationSum({2, 3, 5}, 8))
    {
        for (int value : combination)
            cout << value << " ";
        cout << endl;
    }
}
