#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    int F[3] = {0};
    for (int i = 0; i < n; i++)
    {
        int fx, fy, fz;
        cin >> fx >> fy >> fz;
        F[0] += fx;
        F[1] += fy;
        F[2] += fz;
    }
    if (F[0] || F[1] || F[2])
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }

    return 0;
}
