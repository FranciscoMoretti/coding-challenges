#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int T; cin >> T;

	for (int case_num = 1; case_num <= T; case_num ++) {
		int N; cin >> N;
		vector<string> S(N);
		for (int i = 0; i < N; i++) {
			cin >> S[i];
		};
        auto go = [&]() -> string{
            string pref="";
            vector<string> mid;
            string sub="";
            for (auto&i : S)
            {
                int first = int(i.find_first_of("*"));
                assert(first != string::npos);
                int last = int(i.find_last_of("*"));
                assert(last != string::npos);
                if(first != 0){
                    string pre_i = i.substr(0,first);
                    if (pref.length() == 0){
                        pref.assign(pre_i);
                    }else if(pref.length() < pre_i.length()){
                        if(pref.compare(pre_i.substr(0,pref.length())) == 0){
                            pref.assign(pre_i);
                        }else{
                            return "*";
                        }
                    }else if(pre_i.compare(pref.substr(0,pre_i.length())) != 0){
                                                return "*";
                    }
                }
                if(last != i.length()-1){
                    string pre_i = i.substr(last + 1, i.length());
                    string subr = sub;
                    reverse(subr.begin(), subr.end());
                    reverse(pre_i.begin(), pre_i.end());
                    if (subr.length() == 0){
                        subr.assign(pre_i);
                    }else if(subr.length() < pre_i.length()){
                        if(subr.compare(pre_i.substr(0,subr.length())) == 0){
                            subr.assign(pre_i);
                        }else{
                            return "*";
                        }
                    }else if(pre_i.compare(subr.substr(0,pre_i.length())) != 0){
                        return "*";
                    }
                    reverse(subr.begin(), subr.end());
                    sub = subr;
                }
                if(first != last){
                  int start = first; 
                  int end = first;
                  while(end != last){
                    end = int(i.find_first_of("*", start+1));
                    int len = end-(start+1);
                    if(len > 0){
                        mid.push_back(i.substr(start+1,len));
                    };
                    start = end;
                  }
                }
            }            
            string result = pref;
            for (auto &&i : mid)
            {
                result += i;
            }
            result += sub;
            
            return result;
        };
        string ans = go();
		cout << "Case #" << case_num << ": " << ans << '\n';
	}

	return 0;
}
