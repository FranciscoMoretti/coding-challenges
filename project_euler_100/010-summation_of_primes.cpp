#include <bits/stdc++.h>
using namespace std;

const int max_range = 1000005;

// implementation based on sieve of erathosteles
vector<int> fill_prime_numbers_up_to_n(int n, vector<int> &arr)
{
    int prime_counter = 0;
    vector<int> primes;
    for (size_t i = 2; i < max_range; i++)
    {
        if (!arr[i]) //not a prime
        {
            continue;
        }
        // prime found
        primes.push_back(i);
        if (++prime_counter == n)
        {
            break; //found nth prime
        };
        for (size_t j = i * i; j < max_range; j += i)
        {
            arr[j] = 0;
        }
    }
    return primes;
}

int main()
{
    int T;
    cin >> T;
    vector<int> requests;
    for (size_t i = 0; i < T; i++)
    {
        int in;
        cin >> in;
        requests.push_back(in);
    }

    vector<int> arr = vector<int>(max_range, 1); //10^6
    vector<int> primes = fill_prime_numbers_up_to_n(
        *max_element(requests.begin(), requests.end()), arr);
    for (size_t i = 0; i < T; i++)
    {
        auto it_end = upper_bound(primes.begin(), primes.end(),
                                  requests[i]);
        cout << accumulate(primes.begin(), it_end, 0LL) << endl;
    }
    return 0;
}
