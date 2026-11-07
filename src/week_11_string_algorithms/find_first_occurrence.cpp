#include <iostream>
#include <string>
using namespace std;

int strStr(const string& haystack, const string& needle)
{
    int m = haystack.size();
    int n = needle.size();

    for (int i = 0; i + n <= m; i++)
    {
        int j = 0;
        while (j < n && haystack[i + j] == needle[j])
            j++;

        if (j == n)
            return i;
    }
    return -1;
}

int main()
{
    cout << strStr("sadbutsad", "sad") << endl;
    cout << strStr("leetcode", "leeto") << endl;
    cout << strStr("ksadbutsad", "sad") << endl;
}
