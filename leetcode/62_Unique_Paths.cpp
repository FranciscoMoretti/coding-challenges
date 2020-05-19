#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        if (n < m)
        {
            swap(n, m);
        }
        mat[0][0] = 1;
        for (int k = 0; k < n + m; k++)
        {
            int i = k;
            int j = 0;
            while (i >= 0 && j <= min(k, m - 1))
            {
                if (i <= n)
                {
                    if (i + 1 < n)
                    {
                        mat[i + 1][j] += mat[i][j];
                    }
                    if (j + 1 < m)
                    {
                        mat[i][j + 1] += mat[i][j];
                    }
                }
                i--;
                j++;
            }
        }
        return mat[n - 1][m - 1];
    }

    int uniquePaths2(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int row = 1; row < m; row++)
        {
            for (int col = 1; col < n; col++)
            {
                dp[row][col] = dp[row - 1][col] + dp[row][col - 1];
            }
        }
        return dp[m - 1][n - 1];
    }

private:
    int mat[100][100];
};

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    long int n, m;
    cin >> n >> m;
    Solution solution;
    int result = solution.uniquePaths(n, m);

    cout << result << endl;
    return 0;
}