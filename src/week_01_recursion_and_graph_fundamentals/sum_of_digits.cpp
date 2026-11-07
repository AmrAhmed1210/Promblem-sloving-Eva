#include <iostream>
using namespace std;

int sumOfDigits(int n)
{
    if (n < 10)
        return n;
    return n % 10 + sumOfDigits(n / 10);
}

int main()
{
    cout << sumOfDigits(1234) << endl;
    cout << sumOfDigits(9) << endl;
    cout << sumOfDigits(0) << endl;
}
