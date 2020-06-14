#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int max_range = 1000000;

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
    for (size_t t = 0; t < T; t++)
    {
        string s;
        int len, k;
        cin >> len >> k;
        cin >> s;
        long long accum = 1;
        int count = 0;
        long long max = 0;
        for (size_t j = 0; j < s.size(); j++)
        {
            if (s[j] != '0')
            {
                accum *= s[j] - '0';

                if (++count >= k)
                {
                    if (accum > max)
                    {
                        max = accum;
                    }
                    accum /= s[j - (k - 1)] - '0';
                    count--;
                }
            }
            else
            {
                accum = 1;
                count = 0;
            }
        }
        cout << max << endl;
    }

    return 0;
}
