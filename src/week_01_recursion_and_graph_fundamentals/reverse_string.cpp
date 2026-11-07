#include <iostream>
#include <string>
#include <utility>
using namespace std;

void reverseRange(string& text, int left, int right)
{
    if (left >= right)
        return;

    swap(text[left], text[right]);
    reverseRange(text, left + 1, right - 1);
}

string reverseString(string text)
{
    reverseRange(text, 0, static_cast<int>(text.size()) - 1);
    return text;
}

int main()
{
    cout << reverseString("recursion") << endl;
    cout << reverseString("a") << endl;
    cout << "[" << reverseString("") << "]" << endl;
}
