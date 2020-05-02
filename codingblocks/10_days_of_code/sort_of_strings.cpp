#include <bits/stdc++.h>
#include <cstring>
using namespace std;

#define ll long

string extractStringAtKey(const string &str, int key)
{
    // char *s = strtok((char *)str.c_str(), " ");
    // while (key > 1)
    // {
    //     s = strtok(NULL, " ");
    //     key--;
    // }
    // return (string)s;
    stringstream ss(str);
    string number;
    for (size_t j = 0; j < key; j++)
    {
        ss >> number;
    }
    return number;
}

// We have to apply the pidgeonhole principle

int convertToInt(string s)
{
    int ans = 0;
    int p = 1;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        ans += ((s[i] - '0') * p);
        p *= 10;
    }
}

bool numericCompare(pair<string, string> s1, pair<string, string> s2)
{
    string key1, key2;
    key1 = s1.second;
    key2 = s2.second;
    return stoi(key1) < stoi(key2);
}

bool lexicoCompare(pair<string, string> s1, pair<string, string> s2)
{
    string key1, key2;
    key1 = s1.second;
    key2 = s2.second;
    return key1 < key2;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    vector<string> S;

    long int N;
    cin >> N;
    cin.get();

    //read the input
    for (int i = 0; i < N; i++)
    {
        string str;
        getline(cin, str);
        S.push_back(str);
    }

    int key;
    string ordering;
    string reversal;
    cin >> key >> reversal >> ordering;

    pair<string, string> strPair[100];

    for (int i = 0; i < N; i++)
    {
        strPair[i].first = S[i];
        strPair[i].second = extractStringAtKey(S[i], key);
    }

    // next we need to sort
    if (ordering == "numeric")
    {
        sort(strPair, strPair + N, numericCompare);
    }
    else
    {
        sort(strPair, strPair + N, lexicoCompare);
    }

    if (reversal == "true")
    {
        reverse(strPair, strPair + N);
    }

    // print output
    for (size_t i = 0; i < N; i++)
    {
        cout << strPair[i].first << endl;
    }

    return 0;
}
