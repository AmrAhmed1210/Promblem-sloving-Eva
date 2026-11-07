#include <iostream>
#include <vector>
using namespace std;

int binarySearchRecursive(const vector<int>& arr, int left, int right, int target)
{
    if (left > right)
        return -1;

    int mid = left + (right - left) / 2;

    if (arr[mid] == target)
        return mid;
    if (arr[mid] > target)
        return binarySearchRecursive(arr, left, mid - 1, target);
    return binarySearchRecursive(arr, mid + 1, right, target);
}

int binarySearchIterative(const vector<int>& arr, int target)
{
    int left = 0;
    int right = static_cast<int>(arr.size()) - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main()
{
    vector<int> arr = {1, 3, 5, 7, 9, 11};

    cout << binarySearchRecursive(arr, 0, arr.size() - 1, 7) << endl;
    cout << binarySearchIterative(arr, 7) << endl;
    cout << binarySearchIterative(arr, 4) << endl;
}
