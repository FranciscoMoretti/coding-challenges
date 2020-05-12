#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> L = {4, 7, 47, 74, 474, 477, 747, 774};
    for (int i = 0; i < L.size(); i++)
    {
        if (n % L.at(i) == 0)
        {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
