#include <bits/stdc++.h>

using namespace std;

// Complete the sherlockAndAnagrams function below.
long long int sherlockAndAnagrams(string s)
{
    int len = s.size();
    map<string, int> ordered_subs;
    for (size_t i = 0; i < len; i++)
    {
        for (size_t j = i + 1; j <= len; j++)
        {
            string sub = s.substr(i, j - i);
            sort(sub.begin(), sub.end());
            ordered_subs[sub]++;
        }
    }
    long long unsigned anagrams_count = 0;
    for (auto &&i : ordered_subs)
    {
        if (i.second > 1)
        {
            if (i.second == 2)
            {
                anagrams_count++;
            }
            else
            {
                anagrams_count += (i.second * (i.second - 1)) / 2;
            }
        }
    }

    return anagrams_count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++)
    {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
