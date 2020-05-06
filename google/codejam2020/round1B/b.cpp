#include <bits/stdc++.h>
using namespace std;

const long int LEN = 1000000000;

string query(long int x, long int y)
{
    string result;
    cout << x << " " << y << endl;
    cin >> result;
    return result;
}

void find_center()
{
    int q_count = 0;
    long int curr_x, curr_y;
    // first search for a hit
    for (long int i = 0; i <= 6; i++)
    {
        for (long int j = 0; j <= 6; j++)
        {
            string result = query(i * LEN / 3 - LEN, j * LEN / 3 - LEN);
            q_count++;
            if (result == "CENTER")
            {
                return;
            }
            else if (result == "HIT")
            {
                curr_x = i * LEN / 3 - LEN;
                curr_y = j * LEN / 3 - LEN;
            }
        }
    }
    int l = -1e9, r = curr_x;
    while (l < r)
    {
        int m = l + (r - l) / 2;
        string s = query(m, curr_y);
        if (s == "CENTER")
        {
            return;
        }
        if (s == "HIT")
            r = m;
        else
            l = m + 1;
    }
    int ll = l;
    l = curr_x, r = 1e9;
    while (l < r)
    {
        int m = l + (r - l + 1) / 2;
        string s = query(m, curr_y);
        if (s == "CENTER")
        {
            return;
        }
        if (s == "HIT")
            l = m;
        else
            r = m - 1;
    }
    int rr = r;
    int cx = (ll + rr) / 2;
    l = -1e9, r = curr_y;
    while (l < r)
    {
        int m = l + (r - l) / 2;
        string s = query(cx, m);
        if (s == "CENTER")
        {
            return;
        }
        if (s == "HIT")
            r = m;
        else
            l = m + 1;
    }
    ll = l;
    l = curr_y, r = 1e9;
    while (l < r)
    {
        int m = l + (r - l + 1) / 2;
        string s = query(cx, m);
        if (s == "CENTER")
        {
            return;
        }
        if (s == "HIT")
            l = m;
        else
            r = m - 1;
    }
    rr = r;
    int cy = (ll + rr) / 2;
    string s = query(cx, cy);
    assert(s == "CENTER");
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T;
    long int A, B;
    cin >> T >> A >> B;

    for (int case_num = 1; case_num <= T; case_num++)
    {
        find_center();
    }
    return 0;
}
