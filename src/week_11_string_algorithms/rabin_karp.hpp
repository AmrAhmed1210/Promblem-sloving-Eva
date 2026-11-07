#pragma once

#include <string>

inline long long characterCode(char c)
{
    return static_cast<unsigned char>(c);
}

inline int rabinKarp(const std::string& text, const std::string& pattern)
{
    const long long base = 256;
    const long long mod = 1000000007;
    int n = text.size();
    int m = pattern.size();

    if (m == 0)
        return 0;
    if (m > n)
        return -1;

    long long highestPower = 1;
    for (int i = 1; i < m; i++)
        highestPower = highestPower * base % mod;

    long long patternHash = 0;
    long long windowHash = 0;
    for (int i = 0; i < m; i++)
    {
        patternHash = (patternHash * base + characterCode(pattern[i])) % mod;
        windowHash = (windowHash * base + characterCode(text[i])) % mod;
    }

    for (int i = 0; i + m <= n; i++)
    {
        if (patternHash == windowHash && text.compare(i, m, pattern) == 0)
            return i;

        if (i + m < n)
        {
            windowHash = (windowHash - characterCode(text[i]) * highestPower % mod + mod) % mod;
            windowHash = (windowHash * base + characterCode(text[i + m])) % mod;
        }
    }
    return -1;
}
