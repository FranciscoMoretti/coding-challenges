#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    map<string, int> db;
    for (size_t i = 0; i < n; i++)
    {
        string name;
        cin >> name;
        if (db.count(name))
        {
            int new_num = db[name]++;
            string new_name = name + to_string(new_num);
            cout << new_name << endl;
        }
        else
        {
            db[name] = 1;
            cout << "OK" << endl;
        }
    }
    return 0;
}
