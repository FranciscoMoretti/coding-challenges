#include <bits/stdc++.h>
using namespace std;

// function to find factorial of given number
long long unsigned factorial(unsigned int n)
{
    if (n == 0)
        return 1;
    return (n * factorial(n - 1)) % 1000000007;
}

// C function for extended Euclidean Algorithm (used to
// find modular inverse.
int gcdExtended(int a, int b, int *x, int *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }

    int x1, y1; // To store results of recursive call
    int gcd = gcdExtended(b % a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

// Function to find modulo inverse of b. It returns
// -1 when inverse doesn't
int modInverse(int b, int m)
{
    int x, y; // used in extended GCD algorithm
    int g = gcdExtended(b, m, &x, &y);

    // Return -1 if b and m are not co-prime
    if (g != 1)
        return -1;

    // m is added to handle negative x
    return (x % m + m) % m;
}
// Function to compute a/b under modlo m
long int modDivide(long int a, long int b, long int m)
{
    a = a % m;
    int inv = modInverse(b, m);
    if (inv == -1)
        cout << "Division not defined";
    else
        return (inv * a) % m;
}

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int n, m;
        cin >> n >> m;
        long long unsigned numerator = factorial(n + m);
        long long unsigned denominator = ((factorial(n) * factorial(m)) % 1000000007);
        long long unsigned num_paths = modDivide(numerator, denominator, 1000000007);
        cout << num_paths << endl;
    }

    return 0;
}
