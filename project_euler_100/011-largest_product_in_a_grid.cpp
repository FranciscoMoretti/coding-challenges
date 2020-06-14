#include <bits/stdc++.h>
using namespace std;

long long grid[20][20];
int main()
{

    for (size_t i = 0; i < 20; i++)
    {
        for (size_t j = 0; j < 20; j++)
        {
            int in;
            cin >> in;
            grid[i][j] = in;
        }
    }
    long long int max_found = 0;

    for (size_t i = 0; i < 17; i++)
    {
        for (size_t j = 0; j < 20; j++)
        {
            max_found = max(grid[i][j] * grid[i + 1][j] * grid[i + 2][j] * grid[i + 3][j], max_found);
        }
    }
    for (size_t i = 0; i < 20; i++)
    {
        for (size_t j = 0; j < 17; j++)
        {
            max_found = max(grid[i][j] * grid[i][j + 1] * grid[i][j + 2] * grid[i][j + 3], max_found);
        }
    }
    for (size_t i = 0; i < 17; i++)
    {
        for (size_t j = 0; j < 17; j++)
        {
            max_found = max(grid[i][j] * grid[i + 1][j + 1] * grid[i + 2][j + 2] * grid[i + 3][j + 3], max_found);
        }
    }
    for (size_t i = 3; i < 20; i++)
    {
        for (size_t j = 0; j < 17; j++)
        {
            max_found = max(grid[i][j] * grid[i - 1][j + 1] * grid[i - 2][j + 2] * grid[i - 3][j + 3], max_found);
        }
    }

    cout << max_found << endl;
    return 0;
}
