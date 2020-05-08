#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    long int n;
    cin >> n;

    int count = 0;
    for (size_t i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        s.find('+') != std::string::npos ? count++ : count--;
    }
    cout << count << endl;
    return 0;
}
