#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int row, col;
    for (size_t i = 1; i <= 5; i++)
    {
        for (size_t j = 1; j <= 5; j++)
        {
            int in;
            cin >> in;
            if (in)
            {
                row = i;
                col = j;
            }
        }
    }
    int diff = abs(3 - row) + abs(3 - col);
    cout << diff << endl;
    return 0;
}
