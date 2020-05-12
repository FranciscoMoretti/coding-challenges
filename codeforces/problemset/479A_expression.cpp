#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> combs = {(a + b) * c,
                         a + b * c,
                         a + b + c,
                         a * b * c,
                         a * (b + c),
                         a * b + c};
    int out = *max_element(combs.begin(), combs.end());

    cout << out << endl;
    return 0;
}
