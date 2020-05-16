#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int s, n;
    cin >> s >> n;
    int d_s, inc;
    vector<pair<int, int>> dragons;
    for (int i = 0; i < n; i++)
    {
        cin >> d_s >> inc;
        dragons.push_back(make_pair(d_s, inc));
    }
    sort(dragons.begin(), dragons.end(), [](pair<int, int> first, pair<int, int> second) {
        return first.first < second.first;
    });
    for (auto &&d : dragons)
    {
        if (s > d.first)
        {
            s += d.second;
        }
        else
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
