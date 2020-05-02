#include<bits/stdc++.h>
using namespace std;

void print_top(int n){
    cout << "*" << string(floor(n/2.0f)-1, ' ') << 
        string(ceil(n/2.0f), '*') << endl;
}

void print_middle_1(int n){
    for (size_t i = 0; i < (n-3)/2; i++)
    {
        cout << "*" << string(floor(n/2.0f)-1, ' ') << '*' << endl;
    }
}

void print_middle_2(int n){
    cout << string(n, '*') << endl;
}

void print_middle_3(int n){
    for (size_t i = 0; i < (n-3)/2; i++)
    {
        cout << string(floor(n/2.0f), ' ') << '*' <<
            string(floor(n/2.0f)-1, ' ') << '*' << endl;
    }
}

void print_bottom(int n){
    cout <<  string(ceil(n/2.0f), '*') << 
        string(floor(n/2.0f)-1, ' ') <<  "*" << endl;
}


int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int N; cin >> N;

    print_top(N);
    print_middle_1(N);
    print_middle_2(N);
    print_middle_3(N);
    print_bottom(N);
    
	return 0;
}
