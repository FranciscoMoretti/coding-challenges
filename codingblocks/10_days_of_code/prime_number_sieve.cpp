#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long int n)
{
    if (n == 1)
    {
        return false;
    }
    if (n == 2)
    {
        return true;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

//Sieve Approach -generate array containing prime numbers
void prime_sieve(int *p, int n)
{
    // first mark all odd numbers as prime
    for (int i = 3; i < n; i += 2)
    {
        p[i] = 1;
    }

    // Sieve
    for (int i = 3; i < n; i += 2)
    {
        if (p[i] == 1)
        {
            //mark all the multiples of i as not prime
            for (int j = i * i; j < n; j += i)
            {
                p[j] = 0;
            }
        }
    }
    //special case
    p[2] = 1;
    p[1] = p[0] = 0;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    long long int N;
    cin >> N;

    int p[N] = {0};
    prime_sieve(p, N);

    //lets print primes up to N (not included)
    for (int i = 0; i < N; i++)
    {
        if (p[i] == 1)
        {
            cout << i << " ";
        }
    }

    return 0;
}
