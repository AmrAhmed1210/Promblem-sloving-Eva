#include <iostream>
#include <vector>
using namespace std;

vector<int> sieveOfEratosthenes(int n)
{
    vector<int> primes;
    if (n < 2)
        return primes;

    vector<bool> isPrime(n + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;

    for (int p = 2; p * p <= n; p++)
    {
        if (!isPrime[p])
            continue;
        for (int multiple = p * p; multiple <= n; multiple += p)
            isPrime[multiple] = false;
    }

    for (int number = 2; number <= n; number++)
    {
        if (isPrime[number])
            primes.push_back(number);
    }
    return primes;
}

int main()
{
    for (int prime : sieveOfEratosthenes(50))
        cout << prime << " ";
    cout << endl;
}
