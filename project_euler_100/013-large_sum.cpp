#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    long long unsigned sum = 0;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        string sub = s.substr(0, 13);
        sum += stoull(sub);
    }
    string res = to_string(sum);
    cout << res.substr(0, 10);
    return 0;
}
