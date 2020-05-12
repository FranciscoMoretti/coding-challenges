#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    long int n, l;
    cin >> n >> l;

    vector<long int> L;
    for (size_t i = 0; i < n; i++)
    {
        long int in;
        cin >> in;
        L.push_back(in);
    }
    sort(L.begin(), L.end());
    vector<long int> D(L.size());
    adjacent_difference(L.begin(), L.end(), D.begin());
    long int max_diff = *max_element(D.begin(), D.end());
    long int start = L.front() - 0;
    long int end = l - L.back();
    double radius = max(double(max(start, end)), double(max_diff) / 2);
    cout << fixed << radius << endl;
    return 0;
}
