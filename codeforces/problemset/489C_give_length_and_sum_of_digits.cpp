#include <bits/stdc++.h>
using namespace std;
int i, j, k;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int m, s;
    cin >> m >> s;

    if (s > m * 9 || s < 1 && m > 1)
        cout << "-1"
             << " "
             << "-1";
    else
    {
        for (i = m - 1, k = s; i >= 0; i--)
        {
            int j = max(0, k - 9 * i);
            if (j == 0 && i == m - 1 && k)
                j = 1;
            cout << j;
            k -= j;
        }
        cout << " ";
        for (i = m - 1, k = s; i >= 0; i--)
        {
            int j = min(9, k);
            cout << j;
            k -= j;
        }
    }

    // if (s == 0)
    // {
    //     int res = m == 1 ? 0 : -1;
    //     cout << res << " " << res << endl;
    // }
    // else if (s > 9 * m)
    // {
    //     cout << -1 << " " << -1 << endl;
    // }
    // else if (m == 1)
    // {
    //     cout << s << " " << s << endl;
    // }
    // else
    // {
    //     // s is reacheable
    //     string min = string(m, '0');
    //     string max = string(m, '0');
    //     int nines = s / 9;
    //     int nines_m = nines;
    //     if (s % 9 == 0 && nines < m)
    //     {
    //         nines_m--;
    //     }

    //     for (size_t i = m - nines_m; i < m; i++)
    //     {
    //         min[i] = '9';
    //     }
    //     if (m - nines_m > 1)
    //     {
    //         min[0] = 1 + '0';
    //         min[m - nines_m - 1] = (s - 1) % 9 + '0';
    //     }
    //     else if (m - nines_m > 0)
    //     {
    //         min[0] = s % 9 + '0';
    //     }

    //     for (size_t i = 0; i < nines; i++)
    //     {
    //         max[i] = '9';
    //     }
    //     if (m - nines > 0)
    //     {
    //         max[nines] = s % 9 + '0';
    //     }
    //     cout << min << " " << max << endl;
    // }
    return 0;
}

// m digits
// s sum
// a1...am
// a1+...+am = s
// min ?
// 10..0r9...9          9+...+9+r+1 = s
// 9...9R0...0          9+...+9+R = s