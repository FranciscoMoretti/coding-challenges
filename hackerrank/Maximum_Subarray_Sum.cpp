#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the maximumSum function below.
long maximumSum(vector<long> a, long m)
{
    long long unsigned partial_sum = 0;
    long max_diff = 0;
    vector<pair<int, long>> idx_rem(a.size());
    for (size_t i = 0; i < a.size(); i++)
    {
        partial_sum += a[i];
        long rem = partial_sum % m;
        if (rem > max_diff)
        {
            max_diff = rem;
        }
        idx_rem[i] = {i, rem};
    }
    sort(idx_rem.begin(), idx_rem.end(), [](pair<int, long> a, pair<int, long> b) {
        if ((a.second < b.second) || ((a.second == b.second) && (a.first < b.first)))
        {
            return true;
        }
        else
        {
            return false;
        }
    });
    for (size_t i = 1; i < idx_rem.size(); i++)
    {
        if ((idx_rem[i - 1].second < idx_rem[i].second) && (idx_rem[i - 1].first > idx_rem[i].first))
        {
            max_diff = max(idx_rem[i - 1].second - idx_rem[i].second + m, max_diff);
        }
    }
    cout << max_diff << endl;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++)
    {
        string nm_temp;
        getline(cin, nm_temp);

        vector<string> nm = split_string(nm_temp);

        int n = stoi(nm[0]);

        long m = stol(nm[1]);

        string a_temp_temp;
        getline(cin, a_temp_temp);

        vector<string> a_temp = split_string(a_temp_temp);

        vector<long> a(n);

        for (int i = 0; i < n; i++)
        {
            long a_item = stol(a_temp[i]);

            a[i] = a_item;
        }

        long result = maximumSum(a, m);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string)
{
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ')
    {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos)
    {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
