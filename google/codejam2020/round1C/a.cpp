#include <bits/stdc++.h>
using namespace std;

void make_move(int &x, int &y, char direction)
{
    switch (direction)
    {
    case 'E':
        x++;
        break;
    case 'W':
        x--;
        break;
    case 'N':
        y++;
        break;
    case 'S':
        y--;
        break;
    default:
        assert(0 && "incorrect dir");
        break;
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T;
    cin >> T;

    for (int case_num = 1; case_num <= T; case_num++)
    {
        int X, Y;
        string moves_P;
        cin >> X >> Y >> moves_P;

        int moves = 0;
        bool possible = false;
        for (auto &&i : moves_P)
        {
            make_move(X, Y, i);
            moves++;
            if (moves >= abs(X) + abs(Y))
            {
                possible = true;
                break;
            }
        }
        if (!possible)
        {
            cout << "Case #" << case_num << ": "
                 << "IMPOSSIBLE" << '\n';
        }
        else
        {
            cout << "Case #" << case_num << ": "
                 << moves << '\n';
        }
    }

    return 0;
}
