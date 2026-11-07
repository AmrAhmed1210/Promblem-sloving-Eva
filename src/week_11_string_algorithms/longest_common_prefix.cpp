#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string longestCommonPrefixBruteForce(const vector<string>& words)
{
    if (words.empty())
        return "";

    string prefix = words[0];

    for (size_t i = 1; i < words.size(); i++)
    {
        size_t length = 0;
        while (length < prefix.size() && length < words[i].size() && prefix[length] == words[i][length])
            length++;

        prefix = prefix.substr(0, length);
        if (prefix.empty())
            return "";
    }
    return prefix;
}

string longestCommonPrefixSorted(vector<string> words)
{
    if (words.empty())
        return "";

    sort(words.begin(), words.end());

    const string& first = words.front();
    const string& last = words.back();
    size_t length = 0;

    while (length < first.size() && length < last.size() && first[length] == last[length])
        length++;

    return first.substr(0, length);
}

int main()
{
    vector<string> words = {"flower", "flow", "flight"};
    vector<string> unrelated = {"dog", "racecar", "car"};

    cout << "[" << longestCommonPrefixBruteForce(words) << "]" << endl;
    cout << "[" << longestCommonPrefixSorted(words) << "]" << endl;
    cout << "[" << longestCommonPrefixBruteForce(unrelated) << "]" << endl;
    cout << "[" << longestCommonPrefixSorted(unrelated) << "]" << endl;
}
