#include<bits/stdc++.h>
using namespace std;

int countbits(int n){
    int ans = 0;
    while(n>0){
        ans += (n&1);
        n = n>>1;
    }
    return ans;
}

int countbitsFast(int n){
    int ans = 0;
    while(n>0){
        n = n & (n-1);
        ans++;
    }
    return ans;
}

int builtin_pocount(int n){
    return __builtin_popcount(n);
}

int bitset_class(int n){
    bitset<sizeof(int)*CHAR_BIT> bs(n);
    return bs.count();
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int T; cin >> T;

	for (int case_num = 1; case_num <= T; case_num ++) {
		int N; cin >> N;
		cout << bitset_class(N)<< '\n';
	}

	return 0;
}
