using namespace std;
#include <bits/stdc++.h>

int board[2][100001];
int dp[100001][3];

int main(){
    int t, c;
    cin >> t;
    
    while(t--){
        cin >> c;
        for(int row = 0; row<2; row++){
            for(int col =0; col<c; col++){
                cin >> board[row][col];
            }
        }

        dp[0][0] = board[0][0];
        dp[0][1] = board[1][0];
        dp[0][2] = 0;

        for(int i=1; i<c; i++){
            dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + board[0][i];
            dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + board[1][i];
            dp[i][2] = max({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
        }

        int res = 0;
        res = max({dp[c-1][0], dp[c-1][1], dp[c-1][2]});
        cout << res << '\n';


        // cout << "---resArr---" << '\n';
        // for(int i=0; i<3; i++){
        //     for(int j=0; j<c; j++){
        //         cout << dp[j][i] << ' ';
        //     }
        //     cout << '\n';
        // }
    }
}