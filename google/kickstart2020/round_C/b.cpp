#include <bits/stdc++.h>
using namespace std;

static int R, C;

bool is_placeable(map<char, vector<pair<int, int>>> &dict,
                  vector<vector<char>> &mat, char sel, string &result)
{
    vector<pair<int, int>> sel_cells = dict[sel];
    dict.erase(sel);
    for (auto &&i : sel_cells)
    {
        if ((i.first < R - 1) &&
            mat[i.first + 1][i.second] != sel &&
            result.find(mat[i.first + 1][i.second]) == std::string::npos)
        {
            if (dict.count(mat[i.first + 1][i.second]))
            {
                // check recursion
                if (!is_placeable(dict, mat, mat[i.first + 1][i.second], result))
                {
                    return false;
                }
            }
            else if (result.find(sel) == std::string::npos)
            {
                // cyclic dependency
                return false;
            } // else it's already placed
        }
    }
    result += sel;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T;
    cin >> T;

    for (int case_num = 1; case_num <= T; case_num++)
    {
        cin >> R >> C;
        map<char, vector<pair<int, int>>> dict;
        vector<vector<char>> mat(R, vector<char>(C));
        for (int i = 0; i < R; i++)
        {
            string s;
            cin >> s;
            for (int j = 0; j < C; j++)
            {
                dict[s[j]].push_back(make_pair(i, j));
                mat[i][j] = s[j];
            }
        };

        auto go = [&]() -> string {
            string result = "";
            for (int i = 0; i < R; i++)
            {
                vector<char> row_l = mat[i];
                set<int> s(row_l.begin(), row_l.end());
                row_l.assign(s.begin(), s.end());
                bool new_piece = false;
                int l = 0;
                for (size_t l = 0; l < row_l.size(); l++)
                {
                    char selected = row_l[l];
                    if (result.find(selected) != std::string::npos)
                    {
                        continue;
                    }
                    bool placed = is_placeable(dict, mat, selected, result);
                    if (!placed)
                    {
                        return "-1";
                    }
                }
            }
            return result;
        };
        string ans = go();
        cout << "Case #" << case_num << ": " << ans << '\n';
    }

    return 0;
}
