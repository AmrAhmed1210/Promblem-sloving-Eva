#include <iostream>
#include <vector>
using namespace std;

double dotProduct(const vector<double>& a, const vector<double>& b)
{
    return a[0] * b[0] + a[1] * b[1];
}

double crossProduct2D(const vector<double>& a, const vector<double>& b)
{
    return a[0] * b[1] - a[1] * b[0];
}

vector<double> crossProduct3D(const vector<double>& a, const vector<double>& b)
{
    return {
        a[1] * b[2] - a[2] * b[1],
        a[2] * b[0] - a[0] * b[2],
        a[0] * b[1] - a[1] * b[0]
    };
}

int main()
{
    vector<double> a = {1, 2};
    vector<double> b = {3, 4};

    cout << "Dot product: " << dotProduct(a, b) << endl;
    cout << "Cross product 2D: " << crossProduct2D(a, b) << endl;

    vector<double> c = crossProduct3D({1, 0, 0}, {0, 1, 0});
    cout << "Cross product 3D: (" << c[0] << ", " << c[1] << ", " << c[2] << ")" << endl;
}
