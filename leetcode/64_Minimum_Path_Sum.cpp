#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n;
        if (m != 0)
        {
            n = grid.at(0).size();
        }
        for (int col = 1; col < n; col++)
        {
            grid[0][col] += grid[0][col - 1];
        }
        for (int row = 1; row < m; row++)
        {
            grid[row][0] += grid[row - 1][0];
        }

        for (int row = 1; row < m; row++)
        {
            for (int col = 1; col < n; col++)
            {
                grid[row][col] += min(grid[row - 1][col], grid[row][col - 1]);
            }
        }
        return grid[m - 1][n - 1];
    }
};

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // vector<vector<int>> grid = {
    //     {1, 3, 1},
    //     {1, 5, 1},
    //     {4, 2, 1},
    // };
    vector<vector<int>> grid = {
        {1, 2},
        {1, 1},
    };
    // cin >> grid;
    Solution solution;
    int result = solution.minPathSum(grid);

    cout << result << endl;
    return 0;
}