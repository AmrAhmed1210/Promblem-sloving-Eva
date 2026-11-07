#include <cmath>
#include <iostream>
using namespace std;

void printLineEquation(double x1, double y1, double x2, double y2)
{
    if (x1 == x2)
    {
        cout << "x = " << x1 << endl;
        return;
    }

    if (y1 == y2)
    {
        cout << "y = " << y1 << endl;
        return;
    }

    double slope = (y2 - y1) / (x2 - x1);
    double intercept = y1 - slope * x1;

    cout << "y = " << slope << "x " << (intercept < 0 ? "- " : "+ ") << fabs(intercept) << endl;
}

int main()
{
    printLineEquation(1, 2, 3, 6);
    printLineEquation(0, 5, 2, 1);
    printLineEquation(4, 1, 4, 9);
    printLineEquation(1, 3, 7, 3);
}
