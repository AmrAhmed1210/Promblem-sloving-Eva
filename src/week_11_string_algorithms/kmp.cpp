#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> computeLps(const string& pattern)
{
    int m = pattern.size();
    vector<int> lps(m, 0);
    int length = 0;
    int i = 1;

    while (i < m)
    {
        if (pattern[i] == pattern[length])
        {
            lps[i++] = ++length;
        }
        else if (length != 0)
        {
            length = lps[length - 1];
        }
        else
        {
            lps[i++] = 0;
        }
    }
    return lps;
}

vector<int> kmpSearch(const string& text, const string& pattern)
{
    vector<int> matches;
    int n = text.size();
    int m = pattern.size();

    if (m == 0)
        return matches;

    vector<int> lps = computeLps(pattern);
    int i = 0;
    int j = 0;

    while (i < n)
    {
        if (text[i] == pattern[j])
        {
            i++;
            j++;
        }

        if (j == m)
        {
            matches.push_back(i - j);
            j = lps[j - 1];
        }
        else if (i < n && text[i] != pattern[j])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return matches;
}

int main()
{
    for (int index : kmpSearch("ABABABACABABABAC", "ABABAC"))
        cout << "Pattern found at index " << index << endl;

    for (int index : kmpSearch("aaaaa", "aa"))
        cout << "Pattern found at index " << index << endl;
}
