#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    string s;
    cin >> s;
    string hello = "hello";
    int h_ind = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (hello.at(h_ind) == s.at(i))
        {
            h_ind++;
            if (h_ind == hello.size())
            {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}
