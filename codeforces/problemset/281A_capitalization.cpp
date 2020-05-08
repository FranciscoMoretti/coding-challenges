#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    string s;
    cin >> s;
    s.at(0) = std::toupper(s.at(0));
    cout << s << endl;
    return 0;
}
