#include <iostream>
using namespace std;

long long gcd(long long a, long long b)
{
    return b == 0 ? a : gcd(b, a % b);
}

long long lcm(long long a, long long b)
{
    return a / gcd(a, b) * b;
}

int main()
{
    cout << lcm(4, 6) << endl;
    cout << lcm(21, 6) << endl;
    cout << lcm(1000000007, 998244353) << endl;
}
