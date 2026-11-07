#include <cmath>
#include <iostream>
#include <string>
#include <utility>
using namespace std;

const double EPSILON = 1e-9;

string pointPosition(double x1, double y1, double x2, double y2, double x0, double y0)
{
    if (x1 > x2 || (x1 == x2 && y1 > y2))
    {
        swap(x1, x2);
        swap(y1, y2);
    }

    double cross = (x2 - x1) * (y0 - y1) - (y2 - y1) * (x0 - x1);

    if (fabs(cross) < EPSILON)
        return "on the line";

    bool vertical = (x1 == x2);

    if (cross > 0)
        return vertical ? "left of the line" : "above the line";
    return vertical ? "right of the line" : "below the line";
}

int main()
{
    cout << pointPosition(0, 0, 4, 4, 2, 3) << endl;
    cout << pointPosition(1, 1, 5, 5, 3, 2) << endl;
    cout << pointPosition(2, 2, 6, 6, 4, 4) << endl;
    cout << pointPosition(4, 4, 0, 0, 2, 3) << endl;
    cout << pointPosition(1, 0, 1, 5, 0, 2) << endl;
}
