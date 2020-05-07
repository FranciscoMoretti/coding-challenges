#include <bits/stdc++.h>
using namespace std;

bool is_vowel[CHAR_MAX] = {false}; // initializes all values to false
void init()
{
    is_vowel['A'] = true;
    is_vowel['a'] = true;
    is_vowel['E'] = true;
    is_vowel['e'] = true;
    is_vowel['I'] = true;
    is_vowel['i'] = true;
    is_vowel['Y'] = true;
    is_vowel['y'] = true;
    is_vowel['O'] = true;
    is_vowel['o'] = true;
    is_vowel['U'] = true;
    is_vowel['u'] = true;
}

int main()
{
    init();
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    string S_in;
    cin >> S_in;
    stringstream ss_in = stringstream(S_in);
    stringstream out;
    for (int i = 0; i < S_in.size(); i++)
    {
        char c;
        ss_in >> c;
        if (is_vowel[c])
        {
            continue;
        }
        else
        {
            out << "." << (char)tolower(c);
        }
    }
    cout << out.str() << endl;
    return 0;
}
