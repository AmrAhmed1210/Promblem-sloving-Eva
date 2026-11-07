#include <cmath>
#include <iostream>
#include <string>
using namespace std;

const double EPSILON = 1e-9;

string pointPosition(double m, double c, double x, double y)
{
    double expectedY = m * x + c;

    if (fabs(y - expectedY) < EPSILON)
        return "on the line";
    return y > expectedY ? "above the line" : "below the line";
}

int main()
{
    cout << pointPosition(1, 0, 2, 3) << endl;
    cout << pointPosition(1, 0, 3, 2) << endl;
    cout << pointPosition(1, 0, 4, 4) << endl;
}
