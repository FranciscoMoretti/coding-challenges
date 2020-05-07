#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    long int T, k;
    cin >> T >> k;
    int in;
    int count = 0;
    int k_s = 0;
    for (int i = 1; i <= T; i++)
    {
        cin >> in;
        if (in <= 0 || in < k_s)
        {
            break;
        }
        else
        {
            count++;
        }
        if (i == k)
        {
            k_s = in;
        }
    }

    cout << count << endl;
    return 0;
}
