#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    string s;
    cin >> s;
    set<char> c_set;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (!c_set.count(s.at(i)))
        {
            c_set.insert(s.at(i));
        }
    }
    if (c_set.size() % 2 == 0)
    {
        cout << "CHAT WITH HER!" << endl;
    }
    else
    {
        cout << "IGNORE HIM!" << endl;
    }
    return 0;
}
