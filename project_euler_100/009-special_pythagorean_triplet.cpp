#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Comply with both these equations:
// a+b+c = N
// a^2+b^2 = c^2
// by replacing:
// (N^2-2Na )/ (2*(N-a)) = b
long long special_pithagorian_triplet(long N)
{
    long long N_2 = N * N;
    long long max_val = 0;
    for (long long a = N / 2 - 1; a > 0; a--)
    {
        if (((N_2)-2 * N * a) % (2 * (N - a)) == 0)
        {
            long long b = ((N_2)-2 * N * a) / (2 * (N - a));
            max_val = max(a * b * (N - a - b), max_val);
        }
    }
    return max_val > 0 ? max_val : -1;
}

int main()
{
    int T;
    cin >> T;
    vector<int> requests;
    for (size_t t = 0; t < T; t++)
    {

        int N;
        cin >> N;

        cout << special_pithagorian_triplet(N) << endl;
    }

    return 0;
}
