#include <iostream>
#include <vector>
using namespace std;

int findJudge(int n, const vector<vector<int>>& trust)
{
    vector<int> score(n + 1, 0);

    for (const auto& t : trust)
    {
        score[t[0]]--;
        score[t[1]]++;
    }

    for (int person = 1; person <= n; person++)
    {
        if (score[person] == n - 1)
            return person;
    }
    return -1;
}

int main()
{
    cout << findJudge(2, {{1, 2}}) << endl;
    cout << findJudge(3, {{1, 3}, {2, 3}}) << endl;
    cout << findJudge(3, {{1, 3}, {2, 3}, {3, 1}}) << endl;
    cout << findJudge(1, {}) << endl;
}
