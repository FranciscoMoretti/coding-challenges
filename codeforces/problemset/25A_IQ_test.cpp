#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;

    int first, second, third;
    cin >> first >> second >> third;
    bool even;
    if (first % 2 == second % 2)
    {
        even = (first % 2 == 0);
        if (even != (third % 2 == 0))
        {
            cout << 3 << endl;
            return 0;
        }
    }
    else if (second % 2 == third % 2)
    {
        cout << 1 << endl;
        return 0;
    }
    else if (first % 2 == third % 2)
    {
        cout << 2 << endl;
        return 0;
    }
    else
    {
        assert(0);
    }
    int ind = 3;
    while (ind++ < n)
    {
        int tmp;
        cin >> tmp;
        if (even != (tmp % 2 == 0))
        {
            cout << ind << endl;
            return 0;
        }
    }
    assert(0 && "SHOULD NEVER REACH");
    return 0;
}
