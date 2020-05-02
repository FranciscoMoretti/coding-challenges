#include <bits/stdc++.h>
using namespace std;

//Sieve Approach -generate array containing prime numbers
void prime_sieve(long int *p, long int n)
{
    // first mark all odd numbers as prime
    for (long int i = 3; i < n; i += 2)
    {
        p[i] = 1;
    }

    // Sieve
    for (long int i = 3; i < n; i += 2)
    {
        if (p[i] == 1)
        {
            //mark all the multiples of i as not prime
            for (long int j = i * i; j < n; j += i)
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

    long int N = 101;
    long int p[N] = {0};
    prime_sieve(p, N);

    // partial cummulative sum of primes array
    partial_sum(p, p + N, p);

    int T;
    cin >> T;

    for (int case_num = 1; case_num <= T; case_num++)
    {
        long int a, b;
        cin >> a >> b;
        if (a == 0)
        {
            a = 1;
        }
        cout << p[b] - p[a - 1] << endl;
    }

    return 0;
}
