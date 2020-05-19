#include <bits/stdc++.h>
using namespace std;

int querry(vector<int> &S, int l, int r)
{
    int sum = 0;
    for (int i = l; i <= r; i++)
    {
        int sign = (l - i) % 2 == 0 ? 1 : -1;
        sum += sign * S[i] * (i - l + 1);
    }
    return sum;
}

main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T;
    cin >> T;

    for (int case_num = 1; case_num <= T; case_num++)
    {
        int N, Q;
        cin >> N >> Q;
        vector<int> S(N);
        for (int i = 0; i < N; i++)
        {
            cin >> S[i];
        };
        int result = 0;
        for (int i = 0; i < Q; i++)
        {
            char c;
            int l, r;
            cin >> c >> l >> r;
            if (c == 'Q')
            {
                result += querry(S, l - 1, r - 1);
            }
            else
            {
                S[l - 1] = r;
            }
        }

        cout << "Case #" << case_num << ": " << result << '\n';
    };
}
