#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int T; cin >> T;

	// int n = 31;

	// int C[2 * n + 1][2 * n + 1] = { 0 }; 
  
    // // Calculate value of Binomial Coefficient in 
    // // bottom up manner 
    // for (int i = 0; i <= 2 * n; i++) { 
    //     for (int j = 0; j <= min(i, 2 * n); j++) { 
  
    //         // Base Cases 
    //         if (j == 0 || j == i) 
    //             C[i][j] = 1; 
  
    //         // Calculate value using previously 
    //         // stored values 
    //         else
    //             C[i][j] = C[i - 1][j - 1] + C[i - 1][j]; 
    //     } 
    // } 
	// print for testing
    // for (int i = 0; i < n; i++) { 
    //     for (int j = 0; j < n; j++) 
    //         cout << C[i][j] << " "; 
  
    //     cout << endl; 
    // } 


	for (int case_num = 1; case_num <= T; case_num ++) {
		int N; cin >> N;
        auto go = [&]() -> vector<pair<int,int>>{
            vector<pair<int,int>> walk;
			if (N <= 31){
				for (int i = 1; i <= N; i++)
				{
					walk.push_back(make_pair(i,1));
				}
			}else{
				int N2 = N-31;
				vector<int> sweep_rows;
			
				for (int i = 0; i < 31; i++)
				{
					if( (N2 >> i) % 2 == 1){
						sweep_rows.push_back(i);
					}
				}

				walk.push_back(make_pair(1,1));
				for (auto &&i : sweep_rows)
				{
					if(i == 0){
						continue;
					}
					while(walk.back().first < i){
						int row = walk.back().first;
						if(walk.back().second == 1){
							walk.push_back(make_pair(row+1,1));
						}else{
							walk.push_back(make_pair(row+1,row+1));
						}
					}
					if(walk.back().second == 1){
						for (int j = 1; j <= i+1; j++)
						{
							walk.push_back(make_pair(i+1,j));
						}
					}else{
						for (int j = i+1; j >= 1; j--)
						{
							walk.push_back(make_pair(i+1,j));
						}					}
				}
				int row = walk.back().first;
				while (row < 31 + sweep_rows.size())
				{
					row++;
					if(walk.back().second == 1){
						walk.push_back(make_pair(row,1));
					}else{
						walk.push_back(make_pair(row,row));
					}
				}		
			}
            return walk;
        };
        vector<pair<int,int>> ans = go();
		cout << "Case #" << case_num << ":" << '\n';
		// int check_count = 0;
		for (auto &&i : ans)
		{
			cout << i.first <<" " << i.second << '\n';
			// check_count += C[i.first-1][i.second-1];
		}
		// cout << "COUNT: " << check_count << endl;
	}
	return 0;
}
