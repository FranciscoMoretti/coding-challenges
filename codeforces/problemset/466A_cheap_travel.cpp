#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    int total = 0;
    while (n > 0)
    {
        if (b < min(m, n) * a)
        {
            int sp_pases = n / min(m, n);
            total += sp_pases * b;
            n -= sp_pases * m;
        }
        else
        {
            total += n * a;
            n = 0;
        }
    }

    cout << total << endl;
    return 0;
}

// n - >  - -- - - - -
// m      [      ] @ b
//          a*n