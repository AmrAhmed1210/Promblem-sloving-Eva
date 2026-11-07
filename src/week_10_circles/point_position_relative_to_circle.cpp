#include <cmath>
#include <iostream>
#include <string>
using namespace std;

const double EPSILON = 1e-9;

string pointPosition(double h, double k, double r, double x, double y)
{
    double distanceSquared = (x - h) * (x - h) + (y - k) * (y - k);
    double radiusSquared = r * r;

    if (fabs(distanceSquared - radiusSquared) < EPSILON)
        return "on the circle";
    return distanceSquared < radiusSquared ? "inside the circle" : "outside the circle";
}

int main()
{
    cout << pointPosition(0, 0, 5, 3, 4) << endl;
    cout << pointPosition(0, 0, 5, 1, 1) << endl;
    cout << pointPosition(0, 0, 5, 6, 0) << endl;
    cout << pointPosition(2, 2, 1, 2, 3) << endl;
}
