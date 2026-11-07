#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

const double EPSILON = 1e-9;

struct Circle
{
    double x;
    double y;
    double r;
};

void describeIntersection(const Circle& first, const Circle& second)
{
    double dx = second.x - first.x;
    double dy = second.y - first.y;
    double distance = sqrt(dx * dx + dy * dy);

    if (distance < EPSILON && fabs(first.r - second.r) < EPSILON)
    {
        cout << "The circles coincide" << endl;
        return;
    }

    if (distance > first.r + second.r + EPSILON)
    {
        cout << "The circles are separate" << endl;
        return;
    }

    if (distance < fabs(first.r - second.r) - EPSILON)
    {
        cout << "One circle lies inside the other" << endl;
        return;
    }

    double along = (first.r * first.r - second.r * second.r + distance * distance) / (2 * distance);
    double height = sqrt(max(0.0, first.r * first.r - along * along));

    double baseX = first.x + along * dx / distance;
    double baseY = first.y + along * dy / distance;

    double offsetX = height * dy / distance;
    double offsetY = height * dx / distance;

    if (height < EPSILON)
    {
        cout << "The circles are tangent at (" << baseX << ", " << baseY << ")" << endl;
        return;
    }

    cout << "The circles intersect at (" << baseX + offsetX << ", " << baseY - offsetY << ") and ("
         << baseX - offsetX << ", " << baseY + offsetY << ")" << endl;
}

int main()
{
    describeIntersection({0, 0, 5}, {8, 0, 5});
    describeIntersection({0, 0, 3}, {6, 0, 3});
    describeIntersection({0, 0, 5}, {3, 0, 2});
    describeIntersection({0, 0, 1}, {5, 0, 1});
    describeIntersection({0, 0, 5}, {1, 0, 1});
    describeIntersection({2, 2, 4}, {2, 2, 4});
}
