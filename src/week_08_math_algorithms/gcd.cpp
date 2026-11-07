#include <iostream>
using namespace std;

int gcdRecursive(int a, int b)
{
    if (b == 0)
        return a;
    return gcdRecursive(b, a % b);
}

int gcdIterative(int a, int b)
{
    while (b != 0)
    {
        int remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

int main()
{
    cout << gcdRecursive(48, 18) << endl;
    cout << gcdIterative(48, 18) << endl;
    cout << gcdIterative(17, 5) << endl;
}
