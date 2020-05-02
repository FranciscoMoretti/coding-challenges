#include <bits/stdc++.h>
using namespace std;

void display(int a[][1000], int n)
{
    for (int i = 0; i < n; i++)
    {
    }
    {
        for (int j = 0; j < n; i++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void rotate_stl(int a[][1000], int n)
{
    // reverse (start_container, end_container) methods
    for (int i = 0; i < n; i++)
    {
        reverse(a[i], a[i] + n);
    }

    // transpose
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; i++)
        {
            if (i < j)
            {
                swap(a[i][j], a[j][i]);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int N;
    cin >> N;
    int grid[N][N] = {0};
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> grid[i][j];
        }
    };

    // for (int i = N - 1; i >= 0; i--)
    // {
    //     for (int j = 0; j < N; j++)
    //     {
    //         cout << grid[j][i] << " ";
    //     }
    //     cout << endl;
    // };

    rotate_stl(grid, N);
    display(grid, N);

    return 0;
}
