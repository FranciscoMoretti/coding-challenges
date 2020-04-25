#include<bits/stdc++.h>
using namespace std;


string internal_substr(string& s2, int& i) 
{ 
    int times = 0;
    if(isdigit(s2[i])){
        times = s2[i] - '0';
        i++;//ignore the num
        i++;//ignore the (
    }
    string substring = "";
    while(i < s2.length() && s2[i] != ')'){
        if(isdigit(s2[i])){
            substring += internal_substr(s2, i);
        }else{
            substring += s2[i];
            i++;
        }
    }
    if(times > 0){
        string result = "";
        for (size_t j = 0; j < times; j++)
        {
            result += substring;
        }
        i++;
        return result;  
    }
    else{
        return substring;
    }
} 
  

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int T; cin >> T;
    const long int grid_size = 1000000000;

	for (int case_num = 1; case_num <= T; case_num ++) {
		string S;
        cin >> S;

        auto go = [&]() -> pair<long int, long int>{
            int index = 0;
            string expanded;
            while (index < S.length()){
                expanded += internal_substr(S, index);
            }
            long int row = 1;
            long int col = 1;
            for (auto &&i : expanded)
            {
                switch (i)
                {
                case 'S':
                    row = row+1 <= grid_size ? row+1 : 1;
                    break;
                case 'N':
                    row = row-1 > 0 ? row-1 : grid_size;
                    break;
                case 'E':
                    col = col+1 <= grid_size ? col+1 : 1;
                    break;
                case 'W':
                    col = col-1 > 0 ? col-1 : grid_size;
                    break;
                default:
                    assert(0);
                    break;
                }
            }
            return pair<long int, long int>(col, row);
        };
        pair<long int, long int> ans = go();
        cout << "Case #" << case_num << ": " << ans.first << " " << ans.second << '\n';    
	}
	return 0;
}
