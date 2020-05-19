#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T;
    cin >> T;

    for (int case_num = 1; case_num <= T; case_num++)
    {
        int N;
        cin >> N;
        int k;
        cin >> k;
        vector<int> S(N);
        for (int i = 0; i < N; i++)
        {
            cin >> S[i];
        };
        auto go = [&]() -> int {
            bool counting = false;
            int countdowns = 0;
            for (int i = 0; i < S.size(); i++)
            {
                if (S[i] == k)
                {
                    counting = true;
                }
                else if (counting && i > 0 && S[i] == S[i - 1] - 1)
                {
                    if (S[i] == 1)
                    {
                        countdowns++;
                    }
                }
                else
                {
                    counting = false;
                }
            }

            return countdowns;
        };
        int ans = go();
        cout << "Case #" << case_num << ": " << ans << '\n';
    }

    return 0;
}
