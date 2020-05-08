#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    string s_unordered;
    cin >> s_unordered;
    istringstream iss(s_unordered);
    std::vector<std::string> nums;
    std::string token;
    while (std::getline(iss, token, '+'))
    {
        nums.push_back(token);
    }
    sort(nums.begin(), nums.end());
    for (size_t i = 0; i < nums.size(); i++)
    {
        cout << nums.at(i);
        if (i < nums.size() - 1)
        {
            cout << "+";
        }
    }
    return 0;
}
