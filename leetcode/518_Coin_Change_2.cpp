#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int change_mine(int amount, vector<int> &coins)
    {
        if (coins.size() == 0)
        {
            return amount == 0 ? 1 : 0;
        }
        vector<vector<int>> dp(amount + 1,
                               vector<int>(coins.size(), 0));
        dp[0][0] = 1;
        sort(coins.begin(), coins.end());
        for (int i = 0; i < amount; i++)
        {
            for (int j = 0; j < coins.size(); j++)
            {
                if (dp[i][j])
                {
                    for (int k = j; k < coins.size(); k++)
                    {
                        if (i + coins[k] <= amount)
                        {
                            dp[i + coins[k]][k] += dp[i][j];
                        }
                    }
                }
            }
        }
        int total_combinations = accumulate(dp[amount].begin(), dp[amount].end(), 0);
        return total_combinations;
    }

    // better!!!
    int change(int t, vector<int> &cs)
    {
        int dp[t + 1] = {1};
        for (auto c : cs)
            for (auto j = c; j <= t; ++j)
                dp[j] += dp[j - c];
        return dp[t];
    }
};

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    vector<int> nums = {1, 2, 5};
    int target = 5;

    Solution solution;
    int result = solution.change(target, nums);

    cout << result << endl;
    return 0;
}