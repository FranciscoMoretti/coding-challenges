// C++ efficient program for counting the
// number of numbers <=N having exactly
// 9 divisors
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000;

// sieve method for prime calculation
bool prime[MAX + 1];

// Function to mark the primes
void sieve()
{
    memset(prime, true, sizeof(prime));

    // mark the primes
    for (int p = 2; p * p < MAX; p++)
        if (prime[p] == true)

            // mark the factors of prime as non prime
            for (int i = p * 2; i < MAX; i += p)
                prime[i] = false;
}

// Function for finding no. of divisors
int divCount(int n)
{
    // Traversing through all prime numbers
    int total = 1;
    for (int p = 2; p <= n; p++)
    {
        if (prime[p])
        {

            // calculate number of divisor
            // with formula total div =
            // (p1+1) * (p2+1) *.....* (pn+1)
            // where n = (a1^p1)*(a2^p2)....
            // *(an^pn) ai being prime divisor
            // for n and pi are their respective
            // power in factorization
            int count = 0;
            if (n % p == 0)
            {
                while (n % p == 0)
                {
                    n = n / p;
                    count++;
                }
                total = total * (count + 1);
            }
        }
    }
    return total;
}

// Function to find the first triangular number
vector<int> findNumbers(vector<int> requests)
{

    int n = *max_element(requests.begin(), requests.end());
    vector<int> results(requests.size(), 0);
    if (n == 1)
        return vector<int>(requests.size(), 3);

    // initial number
    int i = 2;

    // initial count of divisors
    int count = 0;

    // prestore the value
    int second = 1;
    int first = 1;

    // iterate till we get the first triangular number
    while (count <= n)
    {

        // even
        if (i % 2 == 0)
        {

            // function call to count divisors
            first = divCount(i + 1);

            // multiply with previous value
            count = first * second;
        }
        // odd step
        else
        {

            // function call to count divisors
            second = divCount((i + 1) / 2);

            // multiply with previous value
            count = first * second;
        }
        i++;
        for (size_t j = 0; j < requests.size(); j++)
        {
            if (results[j] == 0 && count > requests[j])
            {
                results[j] = i * (i - 1) / 2;
            }
        }
    }

    return results;
}

int main()
{
    int T;
    cin >> T;
    vector<int> requests;
    sieve();
    for (size_t i = 0; i < T; i++)
    {
        int in;
        cin >> in;
        requests.push_back(in);
    }
    vector<int> numbers = findNumbers(requests);
    for (size_t i = 0; i < T; i++)
    {
        cout << numbers[i] << endl;
    }
    return 0;
}
