#include <iostream>
#include <vector>
using namespace std;

int maxElement(const vector<int>& values)
{
    int best = values[0];
    for (int value : values)
    {
        if (value > best)
            best = value;
    }
    return best;
}

vector<int> prefixSums(const vector<int>& values)
{
    vector<int> sums(values.size());
    int running = 0;

    for (size_t i = 0; i < values.size(); i++)
    {
        running += values[i];
        sums[i] = running;
    }
    return sums;
}

vector<int> reversed(const vector<int>& values)
{
    return vector<int>(values.rbegin(), values.rend());
}

int main()
{
    vector<int> values = {4, 8, 15, 16, 23, 42};

    cout << "Maximum: " << maxElement(values) << endl;

    cout << "Prefix sums:";
    for (int sum : prefixSums(values))
        cout << " " << sum;
    cout << endl;

    cout << "Reversed:";
    for (int value : reversed(values))
        cout << " " << value;
    cout << endl;
}
