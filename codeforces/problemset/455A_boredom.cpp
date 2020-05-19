#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    vector<long long unsigned> accums(100001, 0);
    for (size_t i = 0; i < n; i++)
    {
        int in;
        cin >> in;
        accums[in] += in;
    }
    long long unsigned even_acc = 0;
    long long unsigned odd_acc = 0;
    long long unsigned total = 0;
    for (int i = 0; i < accums.size(); i++)
    {
        if (i % 2)
        {
            odd_acc += accums[i];
            if (odd_acc < even_acc)
            {
                total += even_acc;
                even_acc = 0;
                odd_acc = 0;
            }
        }
        else
        {
            even_acc += accums[i];
            if (even_acc < odd_acc)
            {
                total += odd_acc;
                even_acc = 0;
                odd_acc = 0;
            }
        }
    }
    total += max(even_acc, odd_acc);
    cout << total << endl;

    return 0;
}
