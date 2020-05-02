#include <bits/stdc++.h>
#include <cstring>
using namespace std;

#define ll long

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    long int N;
    cin >> N;
    cin.get();

    int S[N];

    //read the input
    for (int i = 0; i < N; i++)
    {
        cin >> S[i];
    }
    int to_search;
    cin >> to_search;

    auto iter = std::find(S, S + N, to_search);

    if (iter != S + N)
    {
        cout << std::distance(S, iter) << endl;
    }
    else
    {
        cout << "not found" << endl;
    }

    return 0;
}
