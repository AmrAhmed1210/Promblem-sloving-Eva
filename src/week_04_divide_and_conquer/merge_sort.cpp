#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right)
{
    vector<int> merged;
    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right)
        merged.push_back(arr[i] <= arr[j] ? arr[i++] : arr[j++]);

    while (i <= mid)
        merged.push_back(arr[i++]);

    while (j <= right)
        merged.push_back(arr[j++]);

    for (size_t k = 0; k < merged.size(); k++)
        arr[left + k] = merged[k];
}

void mergeSort(vector<int>& arr, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main()
{
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    mergeSort(arr, 0, arr.size() - 1);

    for (int value : arr)
        cout << value << " ";
    cout << endl;
}
