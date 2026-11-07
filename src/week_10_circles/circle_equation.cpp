#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

string squaredTerm(const string& variable, double center)
{
    ostringstream term;
    term << "(" << variable << (center < 0 ? " + " : " - ") << fabs(center) << ")^2";
    return term.str();
}

void printCircleEquation(double h, double k, double r)
{
    cout << squaredTerm("x", h) << " + " << squaredTerm("y", k) << " = " << r * r << endl;
}

int main()
{
    printCircleEquation(0, 0, 5);
    printCircleEquation(2, -3, 1.5);
}
