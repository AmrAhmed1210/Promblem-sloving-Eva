#include <iostream>
#include <string>
#include "rabin_karp.hpp"
using namespace std;

int repeatedStringMatch(const string& a, const string& b)
{
    string repeated = a;
    int count = 1;

    while (repeated.size() < b.size())
    {
        repeated += a;
        count++;
    }

    if (rabinKarp(repeated, b) != -1)
        return count;

    repeated += a;
    if (rabinKarp(repeated, b) != -1)
        return count + 1;

    return -1;
}

int main()
{
    cout << repeatedStringMatch("abcd", "cdabcdab") << endl;
    cout << repeatedStringMatch("a", "aa") << endl;
    cout << repeatedStringMatch("abc", "wxyz") << endl;
}
