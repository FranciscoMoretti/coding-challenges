#include <cmath>
#include <cstdio>
#include <iostream>
#include "InfInt.h"
using namespace std;

/* Iterative Function to calculate (x^y) in O(log y) */
InfInt power(InfInt x, int y)
{
    InfInt res = 1; // Initialize result

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = res * x;

        // y must be even now
        y = y >> 1; // y = y/2
        x = x * x;  // Change x to x^2
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    int n;
    for (int i = 0; i < t; ++i)
    {
        cin >> n;
        InfInt base = 2;
        InfInt inf_int = power(base, n);
        string result = inf_int.toString();
        int sum_of_digits = 0;
        for (auto &&i : result)
        {
            sum_of_digits += static_cast<int>(i - '0');
        }

        cout << sum_of_digits << endl;
    }
    return 0;
}