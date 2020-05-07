#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T;
    cin >> T;
    string s = ((T > 2 && T % 2 == 0) ? "YES" : "NO");
    cout << s << endl;
    return 0;
}
