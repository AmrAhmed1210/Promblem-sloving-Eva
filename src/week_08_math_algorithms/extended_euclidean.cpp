#include <iostream>
using namespace std;

long long extendedGcd(long long a, long long b, long long& x, long long& y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }

    long long nextX;
    long long nextY;
    long long gcd = extendedGcd(b, a % b, nextX, nextY);

    x = nextY;
    y = nextX - nextY * (a / b);
    return gcd;
}

long long modularInverse(long long a, long long modulus)
{
    long long x;
    long long y;

    if (extendedGcd(a, modulus, x, y) != 1)
        return -1;
    return (x % modulus + modulus) % modulus;
}

int main()
{
    long long x;
    long long y;
    long long gcd = extendedGcd(30, 20, x, y);

    cout << "gcd = " << gcd << ", x = " << x << ", y = " << y << endl;
    cout << "inverse of 3 mod 7 = " << modularInverse(3, 7) << endl;
    cout << "inverse of 2 mod 4 = " << modularInverse(2, 4) << endl;
}
