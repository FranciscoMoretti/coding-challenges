#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T;
    cin >> T;

    for (int case_num = 1; case_num <= T; case_num++)
    {
        int U;
        cin >> U;

        char zero = ' ';

        map<char, long int> frequencies;
        for (long long int i = 0; i < 10e3; i++)
        {
            string qi;
            string ri;
            cin >> qi >> ri;
            (void)qi;
            // find different chars in the code
            char first_dig = ri.at(0);

            if (frequencies.count(first_dig))
            {
                frequencies[first_dig]++;
            }
            else
            {
                frequencies.emplace(first_dig, 1);
            }
            //find the zero char (never shown in the first digit)
            if (ri.size() > 1)
            {
                for (size_t k = 1; k < ri.size(); k++)
                {
                    if (!frequencies.count(ri.at(k)))
                    {
                        zero = ri.at(k);
                    }
                }
            }
        }

        map<long int, char, std::greater<long int>> reversed;
        for (map<char, long int>::iterator i = frequencies.begin(); i != frequencies.end(); ++i)
        {
            reversed[i->second] = i->first;
        }

        string D = {zero};
        for (auto iter = reversed.begin(); iter != reversed.end(); iter++)
        {
            D += iter->second;
        }

        cout << "Case #" << case_num << ": " << D << '\n';
    }

    return 0;
}
