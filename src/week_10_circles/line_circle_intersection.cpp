#include <cmath>
#include <iostream>
using namespace std;

const double EPSILON = 1e-9;

void findLineCircleIntersection(double h, double k, double r, double m, double c)
{
    double a = 1 + m * m;
    double b = 2 * m * (c - k) - 2 * h;
    double d = h * h + (c - k) * (c - k) - r * r;

    double discriminant = b * b - 4 * a * d;

    if (discriminant < -EPSILON)
    {
        cout << "No intersection" << endl;
    }
    else if (fabs(discriminant) <= EPSILON)
    {
        double x = (h - m * (c - k)) / a;
        cout << "One intersection: (" << x << ", " << m * x + c << ")" << endl;
    }
    else
    {
        double root = sqrt(discriminant);
        double x1 = (-b + root) / (2 * a);
        double x2 = (-b - root) / (2 * a);
        cout << "Two intersections: (" << x1 << ", " << m * x1 + c << ") and ("
             << x2 << ", " << m * x2 + c << ")" << endl;
    }
}

int main()
{
    findLineCircleIntersection(0, 0, 5, 0, 0);
    findLineCircleIntersection(0, 0, 5, 0, 5);
    findLineCircleIntersection(0, 0, 5, 0, 6);
}
