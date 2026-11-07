#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int findMaximum(const vector<int>& values, int left, int right)
{
    if (left == right)
        return values[left];

    int mid = left + (right - left) / 2;
    return max(findMaximum(values, left, mid), findMaximum(values, mid + 1, right));
}

int main()
{
    vector<int> values = {7, 2, 19, 4, 11, 8};

    cout << findMaximum(values, 0, values.size() - 1) << endl;
    cout << findMaximum({5}, 0, 0) << endl;
}
