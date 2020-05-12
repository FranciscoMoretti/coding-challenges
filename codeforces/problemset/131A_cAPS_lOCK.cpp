#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    string s;
    cin >> s;
    for (int i = 1; i < s.size(); i++)
    {
        if (!isupper(s.at(i)))
        {
            cout << s << endl;
            return 0;
        }
    }
    string out;
    out += isupper(s.at(0)) ? tolower(s.at(0)) : toupper(s.at(0));
    for (int i = 1; i < s.size(); i++)
    {
        out += tolower(s.at(i));
    }
    cout << out << endl;
    return 0;
}
