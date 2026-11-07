#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string& text, int left, int right)
{
    if (left >= right)
        return true;
    if (text[left] != text[right])
        return false;
    return isPalindrome(text, left + 1, right - 1);
}

int main()
{
    cout << boolalpha;
    cout << isPalindrome("racecar", 0, 6) << endl;
    cout << isPalindrome("hello", 0, 4) << endl;
    cout << isPalindrome("abba", 0, 3) << endl;
}
