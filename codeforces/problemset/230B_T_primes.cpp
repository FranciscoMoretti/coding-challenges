#include <bits/stdc++.h>

using namespace std;
// Function that checks whether n is prime or not
void SieveOfEratosthenesModified(int n, set<long long unsigned> &primes_squared)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p greater than or
            // equal to the square of it
            // numbers which are multiple of p and are
            // less than p^2 are already been marked.
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    // Print all prime numbers
    for (int p = 2; p <= n; p++)
        if (prime[p])
            primes_squared.insert((long long unsigned)p * (long long unsigned)p);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    long int n;
    cin >> n;

    set<long long unsigned> primes_squared;
    primes_squared.insert(4);
    SieveOfEratosthenesModified(1000000, primes_squared);

    for (int i = 0; i < n; i++)
    {
        long long unsigned in;
        cin >> in;
        if (primes_squared.count(in))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
