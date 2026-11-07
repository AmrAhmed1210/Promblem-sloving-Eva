#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int longestCommonSubsequence(const string& first, const string& second)
{
    int n = first.size();
    int m = second.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (first[i - 1] == second[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}

int main()
{
    cout << longestCommonSubsequence("abcde", "ace") << endl;
    cout << longestCommonSubsequence("abc", "abc") << endl;
    cout << longestCommonSubsequence("abc", "def") << endl;
}
