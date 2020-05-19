#include <bits/stdc++.h>
using namespace std;

static bool arr[100000000] = {false};

main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T;
    cin >> T;

    set<long> perfSquares;
    long i = 0;
    // perfSquares.insert(0);
    arr[0] = true;
    for (long n = i * i; i < 10000; i++)
    {
        n += 2 * i + 1;
        arr[n] = true;
        // perfSquares.insert(n);
    }

    for (int case_num = 1; case_num <= T; case_num++)
    {
        int N;
        cin >> N;
        vector<int> S(N);
        for (int i = 0; i < N; i++)
        {
            cin >> S[i];
        };
        int result = 0;
        for (int i = 0; i < N; i++)
        {
            int sum = 0;
            for (int j = i; j < N; j++)
            {
                sum += S[j];
                // if (sum >= 0 && perfSquares.count(sum))
                if (sum >= 0 && arr[sum])
                {
                    result++;
                }
            }
        }

        cout << "Case #" << case_num << ": " << result << '\n';
    };
}
