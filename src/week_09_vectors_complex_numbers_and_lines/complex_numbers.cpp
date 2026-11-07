#include <complex>
#include <iostream>
using namespace std;

int main()
{
    complex<double> first(3, 2);
    complex<double> second(1, 5);

    cout << "Addition: " << first + second << endl;
    cout << "Subtraction: " << first - second << endl;
    cout << "Multiplication: " << first * second << endl;
    cout << "Division: " << first / second << endl;
}
