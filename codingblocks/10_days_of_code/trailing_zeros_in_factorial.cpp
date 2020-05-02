#include<bits/stdc++.h>
using namespace std;


// To find the times that N! is divisible by 10 we found the times it's
// disvisible by 5, because 10 = 5*2 and there are more ocurrences of 2 than
// there is of 5.
// We can divide by 5, 5^2, 5^3, ... until we found a number greater than N
int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	long long int N; cin >> N;

    long int trailing_zeros = 0;
    for( long long int pow_5 = 5; pow_5 <= N; pow_5 *= 5){
        trailing_zeros += N/pow_5;
    }
    cout << trailing_zeros << endl;


	return 0;
}
