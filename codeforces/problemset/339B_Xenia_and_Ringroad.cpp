#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int destiny;
    int xenia = 1;
    long long time = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> destiny;
        long long inc = xenia <= destiny ? destiny - xenia : n + destiny - xenia;
        xenia = destiny;
        time += inc;
    }
    cout << time << endl;
    return 0;
}
