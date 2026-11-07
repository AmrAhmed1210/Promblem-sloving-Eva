#include <iostream>
#include "rabin_karp.hpp"
using namespace std;

int main()
{
    cout << rabinKarp("abcde", "abc") << endl;
    cout << rabinKarp("HappyOrsad", "Or") << endl;
    cout << rabinKarp("abcde", "xyz") << endl;
    cout << rabinKarp("abc", "abcd") << endl;
}
