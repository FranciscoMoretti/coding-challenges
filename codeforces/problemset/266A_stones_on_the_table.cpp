#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int tmp;
    cin >> tmp;
    string s;
    cin >> s;
    int count = 0;
    for (size_t i = 0; i < s.size() - 1; i++)
    {
        if (s.at(i) == s.at(i + 1))
        {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
