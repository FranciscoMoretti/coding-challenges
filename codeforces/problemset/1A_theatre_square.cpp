#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    long int n, m, a;
    cin >> n >> m >> a;
    long long int needed = ceil(double(n)/a) * ceil(double(m)/a);   
    cout << needed << endl;
    return 0;
}
