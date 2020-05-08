#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    string s1, s2;
    cin >> s1 >> s2;
    std::transform(s1.begin(), s1.end(), s1.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    std::transform(s2.begin(), s2.end(), s2.begin(),
                   [](unsigned char c) { return std::tolower(c); });

    int result = s1.compare(s2) < 0 ? -1 : s1.compare(s2) > 0 ? 1 : 0;
    cout << result << endl;
    return 0;
}
