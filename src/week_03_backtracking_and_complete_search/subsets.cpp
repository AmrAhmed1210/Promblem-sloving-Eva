#include <iostream>
#include <vector>
using namespace std;

void generateSubsets(int index, vector<int>& current, vector<vector<int>>& result, const vector<int>& nums)
{
    if (index == static_cast<int>(nums.size()))
    {
        result.push_back(current);
        return;
    }

    generateSubsets(index + 1, current, result, nums);

    current.push_back(nums[index]);
    generateSubsets(index + 1, current, result, nums);
    current.pop_back();
}

vector<vector<int>> subsets(const vector<int>& nums)
{
    vector<vector<int>> result;
    vector<int> current;
    generateSubsets(0, current, result, nums);
    return result;
}

int main()
{
    for (const auto& subset : subsets({1, 2, 3}))
    {
        cout << "[ ";
        for (int value : subset)
            cout << value << " ";
        cout << "]" << endl;
    }
}
