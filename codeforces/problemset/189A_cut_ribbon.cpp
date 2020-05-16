#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    int a, b, c;
    cin >> a >> b >> c;

    int dp[n + 1];
    fill(dp, dp + n + 1, -1e10);
    dp[0] = 0;
    for (int i = a; i <= n; i++)
        dp[i] = max(dp[i], dp[i - a] + 1);
    for (int i = b; i <= n; i++)
        dp[i] = max(dp[i], dp[i - b] + 1);
    for (int i = c; i <= n; i++)
        dp[i] = max(dp[i], dp[i - c] + 1);
    cout << dp[n];

    return 0;
}
