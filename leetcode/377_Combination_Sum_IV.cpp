#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        vector<long long unsigned> dp(target + 1, 0);
        dp[target] = 1;
        for (int i = dp.size() - 1; i > 0; i--)
        {
            for (size_t j = 0; j < nums.size(); j++)
            {
                if (i - nums[j] >= 0)
                {
                    dp[i - nums[j]] += dp[i];
                }
            }
        }
        return dp[0];
    }
};

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    vector<int> nums = {3, 33, 333};
    int target = 10000;

    Solution solution;
    int result = solution.combinationSum4(nums, target);

    cout << result << endl;
    return 0;
}