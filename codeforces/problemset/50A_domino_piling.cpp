#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    long int n, m;
    cin >> n >> m;
    int even_sq = (n / 2) * (m / 2) * 2;
    int n_extra = n % 2 * (m / 2);
    int m_extra = m % 2 * (n / 2);

    cout << even_sq + n_extra + m_extra << endl;
    return 0;
}
