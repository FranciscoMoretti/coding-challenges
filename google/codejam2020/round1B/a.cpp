#include<bits/stdc++.h>
using namespace std;

string print_sequence(pair<vector<long int>,vector<long int>> p, bool invX,bool invY){
    string seq;
    char posX = invX ? 'W' : 'E';
    char negX = invX ? 'E' : 'W';
    char posY = invY ? 'S' : 'N';
    char negY = invY ? 'N' : 'S';
    int len = max(p.first.size(), p.second.size());
    for (size_t i = 0; i < len; i++)
    {
        if(i < p.first.size()){
            if( p.first[i]!=0){
                seq.push_back(p.first[i] == 1 ? posX : negX);
            }
        }
        if(i < p.second.size()){
            if( p.second[i]!=0){
                seq.push_back(p.second[i] == 1 ? posY : negY);
            }
        }
    }
    return seq;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int T; cin >> T;


	for (int case_num = 1; case_num <= T; case_num ++) {
		long int X, Y; cin >> X >> Y;
        // To array
        long int Xabs = abs(X);
        long int Yabs = abs(Y);
        vector<long int> x1, x2, y1, y2;
        long int power = 0;
        while( (long int) (1 << power) <= Xabs){
            x1.push_back((Xabs >> power)%2);
            power ++;
        }
        long int Xc = (long int) (1 << power) - Xabs;
        for (int i = 0; i < power; i++)
        {
            x2.push_back(-1*((Xc >> i)%2));
        }
        x2.push_back(1);
    
        power = 0;
        while((long int) (1 << power) <= Yabs){
            y1.push_back((Yabs >> power)%2);
            power ++;
        }
        long int Yc = (long int) (1 << power) - Yabs;
        for (int i = 0; i < power; i++)
        {
            y2.push_back(-1*((Yc >> i)%2));
        }
        y2.push_back(1);

        // for (auto &&i : x1){cout << i << " ";}; cout << endl;
        // for (auto &&i : x2){cout << i << " ";}; cout << endl;
        // for (auto &&i : y1){cout << i << " ";}; cout << endl;
        // for (auto &&i : y2){cout << i << " ";}; cout << endl;

        if(x1.size() == 0){
            if(find(y1.begin(),y1.end(), 0) != y1.end()){
                cout << "Case #" << case_num << ": "<< "IMPOSSIBLE" <<  '\n';
            }else{
                string sequence = print_sequence(make_pair(x1,y1), X<0, Y<0);
        		cout << "Case #" << case_num << ": "<< sequence << '\n';
            }
            continue;

        }
        if(y1.size() == 0){
            if(find(x1.begin(),x1.end(), 0) != x1.end()){
                cout << "Case #" << case_num << ": "<< "IMPOSSIBLE" <<  '\n';
            }else{
                string sequence = print_sequence(make_pair(x1,y1), X<0, Y<0);
        		cout << "Case #" << case_num << ": "<< sequence << '\n';
            }
            continue;
        }

        //try combinations
        vector<pair<vector<long int>,vector<long int>>> combs;
        combs.push_back(make_pair(x1,y1));
        combs.push_back(make_pair(x1,y2));
        combs.push_back(make_pair(x2,y1));
        combs.push_back(make_pair(x2,y2));
        auto go = [&]() -> pair<vector<long int>,vector<long int>>{
            for (auto &&c : combs)
            {
                int len = min(c.first.size(), c.second.size());
                bool possible = true;
                int i = 0;
                while (i < len)
                {
                    if(abs(c.first[i]+c.second[i]) != 1){
                        possible = false;
                        break;
                    }
                    i++;
                }
                if(possible == false){
                    continue;
                }
                if(c.first.size() > len){
                    bool gap_used = false;
                    int zero_count = 0;
                    for (int j = len; j < c.first.size(); j++)
                    {
                        if(c.first[j] != 0){
                            if(!gap_used){
                                gap_used = true;
                            }
                        }
                        if(c.first[j] == 0){
                            zero_count ++;
                            if(gap_used){
                                possible = false;
                                break;
                            }
                        }
                    }
                    if(possible == false){
                        continue;
                    }
                    vector<long int> ycopy = c.second;
                    if(zero_count > 0){
                        long int sign = ycopy[len-1];
                        for (int j = len - 1; j <= len - 1 + zero_count; j++)
                        {
                            if(j == len - 1 + zero_count){
                                ycopy.push_back(sign);
                            }else if(j == len - 1){
                                ycopy[j] = -sign;
                            }else{
                                ycopy.push_back(-sign);
                            }
                        }
                    }
                    return make_pair(c.first,ycopy);
                }else if(c.second.size() > len){
                    bool gap_used = false;
                    int zero_count = 0;
                    for (int j = len; j < c.second.size(); j++)
                    {
                        if(c.second[j] != 0){
                            if(!gap_used){
                                gap_used = true;
                            }
                        }
                        if(c.second[j] == 0){
                            zero_count ++;
                            if(gap_used){
                                possible = false;
                                break;
                            }
                        }
                    }
                    if(possible == false){
                        continue;
                    }
                    vector<long int> xcopy = c.first;
                    if(zero_count > 0){
                        long int sign = xcopy[len-1];
                        for (int j = len - 1; j <= len - 1 + zero_count; j++)
                        {
                            if(j == len - 1 + zero_count){
                                xcopy.push_back(sign);
                            }else if(j == len - 1){
                                xcopy[j] = -sign;
                            }else{
                                xcopy.push_back(-sign);
                            }
                        }
                    }
                    return make_pair(xcopy,c.second);
                }
                return c;
            }
            
            vector<long int> empty;
            return make_pair(empty,empty);
        };
        pair<vector<long int>,vector<long int>> ans = go();
        if(ans.first.size() == 0 && ans.second.size() == 0){
            cout << "Case #" << case_num << ": "<< "IMPOSSIBLE" <<  '\n';
            continue;
        }
        string sequence = print_sequence(ans, X<0, Y<0);
        // cout << "solution" << endl;
        // for (auto &&i : ans.first){cout << i << " ";}; cout << endl;
        // for (auto &&i : ans.second){cout << i << " ";}; cout << endl;
		cout << "Case #" << case_num << ": "<< sequence << '\n';
	}

	return 0;
}
