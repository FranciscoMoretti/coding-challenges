#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    int grs[5] = {0};
    for (int i = 0; i < n; i++)
    {
        int g_n;
        cin >> g_n;
        grs[g_n]++;
    }
    int taxi_count = grs[4];
    if (grs[3])
    {
        taxi_count += grs[3];
        grs[1] = max(grs[1] - grs[3], 0);
    }
    if (grs[2])
    {
        taxi_count += ceil(double(grs[2]) / 2);
        if (grs[2] % 2)
        {
            grs[1] = max(grs[1] - 2, 0);
        }
    }
    taxi_count += ceil(double(grs[1]) / 4);

    cout << taxi_count << endl;

    return 0;
}
