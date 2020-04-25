#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int T; cin >> T;

	for (int case_num = 1; case_num <= T; case_num ++) {
		int N; cin >> N;
		vector<int> S(N);
		for (int i = 0; i < N; i++) {
			cin >> S[i];
		};
        auto go = [&]() -> int{
            int peaks = 0; 
            for (int i = 1; i < S.size()-1; i++)
            {
                if(S[i] > S[i-1] && S[i] > S[i+1]){
                    peaks++;
                }
            }
            
            return peaks;
        };
        int ans = go();
		cout << "Case #" << case_num << ": " << ans << '\n';
	}

	return 0;
}
