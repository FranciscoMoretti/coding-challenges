#include <bits/stdc++.h>
using namespace std;

int arr[500001] = {0};

int collatz(long long int n)
{
    if (n == 1)
    {
        return 0;
    }
    else if (n < 500001)
    {
        if (arr[n] != 0)
        {
            return arr[n];
        }
    }
    int count = (n % 2 == 0) ? collatz(n / 2) : collatz(n * 3 + 1);
    if (n < 500001)
    {
        arr[n] = count + 1;
    }
    return count + 1;
}

bool sortbysec(const pair<int, int> &a,
               const pair<int, int> &b)
{
    return (a.second < b.second);
}

int main()
{
    int T;
    cin >> T;
    vector<pair<int, int>> request_idx;
    int limit = 0;
    for (int i = 0; i < T; i++)
    {
        int n;
        cin >> n;
        request_idx.push_back({n, i});
        limit = max(n, limit);
    }
    // sort using the first element
    sort(request_idx.begin(), request_idx.end());

    vector<int> results(request_idx.size(), 0);
    auto request_it = request_idx.begin();
    int max_collatz = 0;
    int max_collatz_i = 0;
    for (int i = 1; i <= limit; i++)
    {
        int collatz_i = collatz(i);
        if (collatz_i >= max_collatz)
        {
            max_collatz = collatz_i;
            max_collatz_i = i;
        }
        while (i == (*request_it).first)
        {
            (*request_it).first = max_collatz_i;
            request_it++;
        }
    }
    sort(request_idx.begin(), request_idx.end(), sortbysec);

    for (auto &&result : request_idx)
    {
        cout << result.first << endl;
    }
    return 0;
}
