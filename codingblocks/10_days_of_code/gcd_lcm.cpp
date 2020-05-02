#include<bits/stdc++.h>
using namespace std;

long long int gcd(long long int N1, long long int N2){
    return N2 == 0 ? N1 : gcd(N2, N1%N2);
}

long long int lcm(long long int N1, long long int N2){
    return N1*N2/gcd(N1,N2);
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    long long int N1, N2; cin >> N1 >> N2;
    cout << gcd(N1, N2)<< '\n';

	return 0;
}
