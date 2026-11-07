#include <iostream>
using namespace std;

double power(double base, long long exponent)
{
    if (exponent < 0)
        return power(1.0 / base, -exponent);

    if (exponent == 0)
        return 1;

    double half = power(base, exponent / 2);
    return exponent % 2 == 0 ? half * half : half * half * base;
}

int main()
{
    cout << power(2, 10) << endl;
    cout << power(2, -2) << endl;
    cout << power(2.1, 3) << endl;
}
