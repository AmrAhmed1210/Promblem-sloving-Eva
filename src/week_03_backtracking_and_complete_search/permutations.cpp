#include <iostream>
#include <vector>
using namespace std;

void permute(const vector<int>& nums, vector<bool>& used, vector<int>& current, vector<vector<int>>& result)
{
    if (current.size() == nums.size())
    {
        result.push_back(current);
        return;
    }

    for (size_t i = 0; i < nums.size(); i++)
    {
        if (used[i])
            continue;

        used[i] = true;
        current.push_back(nums[i]);
        permute(nums, used, current, result);
        current.pop_back();
        used[i] = false;
    }
}

vector<vector<int>> permutations(const vector<int>& nums)
{
    vector<vector<int>> result;
    vector<int> current;
    vector<bool> used(nums.size(), false);
    permute(nums, used, current, result);
    return result;
}

int main()
{
    for (const auto& permutation : permutations({1, 2, 3}))
    {
        for (int value : permutation)
            cout << value << " ";
        cout << endl;
    }
}
