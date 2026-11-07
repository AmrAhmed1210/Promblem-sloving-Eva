#include <cstdint>
#include <iostream>
using namespace std;

uint32_t reverseBits(uint32_t n)
{
    uint32_t result = 0;

    for (int i = 0; i < 32; i++)
    {
        result = (result << 1) | (n & 1);
        n >>= 1;
    }
    return result;
}

int main()
{
    cout << reverseBits(43261596) << endl;
    cout << reverseBits(4294967293u) << endl;
}
