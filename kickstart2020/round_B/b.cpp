#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int T; cin >> T;

	for (int case_num = 1; case_num <= T; case_num ++) {
		int N; cin >> N;
        long long int D; cin >> D;
		vector<long long int> S(N);
		for (int i = 0; i < N; i++) {
			cin >> S[i];
		};
        auto go = [&]() -> long long int{
            string pref="";
            vector<string> mid;
            string sub="";
            for (int i = S.size() - 1; i >= 0; i--)
            {
                long long int rem = D%S[i];
                D -= rem;
            }
            return D;
        };
        long long int ans = go();
		cout << "Case #" << case_num << ": " << ans << '\n';
	}

	return 0;
}
