#include <cmath>
#include <iostream>
using namespace std;

const double EPSILON = 1e-9;

void findIntersection(double m1, double c1, double m2, double c2)
{
    if (fabs(m1 - m2) < EPSILON)
    {
        if (fabs(c1 - c2) < EPSILON)
            cout << "The lines are the same" << endl;
        else
            cout << "The lines are parallel" << endl;
        return;
    }

    double x = (c2 - c1) / (m1 - m2);
    double y = m1 * x + c1;

    cout << "The lines intersect at (" << x << ", " << y << ")" << endl;
}

int main()
{
    findIntersection(1, 0, -1, 4);
    findIntersection(2, 1, 2, 5);
    findIntersection(3, 2, 3, 2);
}
