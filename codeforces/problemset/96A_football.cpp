#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    string s;
    cin >> s;
    int accum = 1;
    for (size_t i = 0; i < s.size() - 1; i++)
    {
        s.at(i) == s.at(i + 1) ? accum++ : accum = 1;
        if (accum == 7)
        {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
