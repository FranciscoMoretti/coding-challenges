#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

struct status
{
    unsigned long long m;
    unsigned long long w;
    unsigned long long c;
};

void distribute_investment(unsigned long long &m, unsigned long long &w, unsigned long long inc)
{

    unsigned long long m_plus_w_inc = m + w + inc;
    unsigned long long n1 = min(min(m + inc, m_plus_w_inc / 2ULL), w + inc);
    unsigned long long n2 = m_plus_w_inc - n1;

    m = n1;
    w = n2;
}

status step(status inp, unsigned long long invest, unsigned long long p)
{
    status ret = inp;

    distribute_investment(ret.m, ret.w, invest / p);
    ret.c -= invest;
    ret.c += ret.m * ret.w;

    return ret;
}

unsigned long long how_many_steps(status inp, unsigned long long n)
{
    if (inp.c >= n)
    {
        return 0;
    }

    if (((n - inp.c) / inp.m) < inp.w)
    {
        return 1;
    }

    unsigned long long a = n - inp.c;
    //cout << "how_many_steps n = " << n << ", inp.c = " << inp.c << std::endl;
    unsigned long long ret = a / inp.m / inp.w;
    //cout << "how_many_steps a = " << a << ", ret = " << ret << std::endl;
    unsigned long long ret_remainder1 = a % inp.m;
    unsigned long long ret_remainder2 = (a / inp.m) % inp.w;

    return ret_remainder1 || ret_remainder2 ? ret + 1 : ret;
}

// Complete the minimumPasses function below.
long minimumPasses(unsigned long long m, unsigned long long w, unsigned long long p, unsigned long long n)
{
    status st{m, w, 0};

    unsigned long long counter = 0;

    unsigned long long cheap_steps = 0;

    status all_in_st;
    unsigned long long all_in_steps = 0;
    unsigned long long max_investment = 0;

    while (st.c < n)
    {
        if ((n / st.m) < st.w)
        {
            return counter + 1;
        }

        //cout << st.m << " " << st.w << " " << st.c << " " << counter << std::endl;
        max_investment = st.c - (st.c % p);
        if (max_investment == 0 && (p <= n))
        {
            unsigned long long to = how_many_steps(st, p);
            counter += to;
            st.c += st.m * st.w * to;
            continue;
        }
        all_in_st = step(st, max_investment, p);
        all_in_steps = how_many_steps(all_in_st, n) + 1;

        cheap_steps = how_many_steps(st, n);

        if (all_in_steps <= cheap_steps)
        {
            //cout << "entro " << all_in_steps << " " << cheap_steps << std::endl;
            st = all_in_st;
        }
        else
        {
            //cout << "no entro " << all_in_steps << " " << cheap_steps << std::endl;
            return counter + cheap_steps;
        }

        counter++;
    }

    return counter;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string mwpn_temp;
    getline(cin, mwpn_temp);

    vector<string> mwpn = split_string(mwpn_temp);

    unsigned long long m = stoull(mwpn[0]);

    unsigned long long w = stoull(mwpn[1]);

    unsigned long long p = stoull(mwpn[2]);

    unsigned long long n = stoull(mwpn[3]);

    unsigned long long result = minimumPasses(m, w, p, n);

    fout << result << "\n";

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