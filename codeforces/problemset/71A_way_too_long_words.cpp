#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    long int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        string in;
        cin >> in;
        if (in.size() > 10)
        {
            cout << in.front() << in.size() - 2 << in.back() << endl;
        }
        else
        {
            cout << in << endl;
        }
    }
    return 0;
}
