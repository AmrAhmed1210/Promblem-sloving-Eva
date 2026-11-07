#include <iostream>
#include <vector>
using namespace std;

int searchInsert(const vector<int>& nums, int target)
{
    int left = 0;
    int right = static_cast<int>(nums.size()) - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
            return mid;
        if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

int main()
{
    vector<int> nums = {1, 3, 5, 6};

    cout << searchInsert(nums, 5) << endl;
    cout << searchInsert(nums, 2) << endl;
    cout << searchInsert(nums, 7) << endl;
    cout << searchInsert(nums, 0) << endl;
}
