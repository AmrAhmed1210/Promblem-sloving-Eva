#include <iostream>
#include <vector>
using namespace std;

int majorityElement(const vector<int>& nums)
{
    int candidate = 0;
    int count = 0;

    for (int value : nums)
    {
        if (count == 0)
            candidate = value;
        count += (value == candidate) ? 1 : -1;
    }
    return candidate;
}

int main()
{
    cout << majorityElement({3, 2, 3}) << endl;
    cout << majorityElement({2, 2, 1, 1, 1, 2, 2}) << endl;
}
