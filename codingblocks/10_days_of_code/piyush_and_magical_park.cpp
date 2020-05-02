#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    
    int N, M, K, S; cin >> N >> M >> K >> S;
    char grid[N][M] = {' '};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    };

    const char OBS = '.';
    const char BEAN = '*';
    const char BLOCKADE = '#';

    int row = 0;
    int col = 0;
    while(row < N){           

        switch (grid[row][col])
        {
            case OBS:
                S -= 2;
                col++;
                break;
            case BEAN:
                S += 5;
                col++;
                break;
            case BLOCKADE:
                row++;
                col = 0;
                break;
            default:
                assert(0 && "wrong char");
                break;
        }
        if(col == M){
            col = 0;
            row += 1;
        }else if(col != 0){
            S--;
        }
        if(S <= K ){
            break;
        }
    }
    if(row == N){
        cout << "Yes" << endl;
        cout << S << endl;
    }else{
        cout << "No" << endl;
    }
        
	return 0;
}
