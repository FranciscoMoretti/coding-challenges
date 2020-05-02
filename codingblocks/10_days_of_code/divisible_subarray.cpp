#include <bits/stdc++.h>
#include <cstring>
using namespace std;

#define ll long

ll int a[1000005], pre[1000005];
// We have to apply the pidgeonhole principle
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T;
    cin >> T;

    for (int case_num = 1; case_num <= T; case_num++)
    {
        long int N;
        cin >> N;
        memset(pre, 0, sizeof(pre));

        pre[0] = 1;
        //read the input
        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            cin >> a[i];
            sum += a[i];
            sum %= N;
            sum = (sum + N) % N; // make it positive
            pre[sum]++;
        }

        ll ans = 0;
        for (int i = 0; i < N; i++)
        {
            ll m = pre[i];
            ans += m * (m - 1) / 2;
        }
        cout << ans << endl;
    }

    return 0;
}
