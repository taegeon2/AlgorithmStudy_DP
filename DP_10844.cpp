#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 1000000000

ll dp[101][10]; //dp[i][j] => i자리 수가 끝자리 숫자가 j인 수의 개수

/*
길이가 1:
1~9 : 9
dp[1][0] = 0  dp[1][9] = 1  dp[1][1~8] = 8

길이가 2:
12 23 34 45 56 67 78      89
21 32 43 54 65 76 87 98
10  => 17개
dp[2][0] = 1   dp[2][9] = 1  dp[2][1~8] = 15
(dp[2][0] = dp[2-1][9] / dp[2][9] = dp[2-1][8])

길이가 3:
0으로 끝나는 수: 210
9로 끝나는 수 : 789, 989
1로 끝나는 수 : 321 121
do[3][0] = 1  dp[3][9] = 2 dp[3][2~8] = 29


길이가 4:
0으로 끝나는 수: 3210, 1210, 1010
9로 끝나는 수 : 6789, 8989, 8789
do[3][0] = 1  dp[3][9] = 2 dp[3][2~8] = 29
n단계 계단수는 결국 n-1단계 계단수의 영향을 받을텐데..
 */

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    dp[1][0] = 0;
    dp[1][9] = 1;
    for(int i=1; i<=8; i++)
        dp[1][i] = 1;

    for(int i=2; i<=100; i++){
        dp[i][0] = dp[i-1][1] % MOD;
        dp[i][9] = dp[i-1][8] % MOD;
        for(int j=1; j<=8; j++){
            dp[i][j] =(dp[i-1][j-1] + dp[i-1][j+1]) % MOD; // XX3 -> 12  54
        }
    }

    ll res = 0;
    for(int i=0; i<=9; i++){
        res += dp[n][i];
    }
    cout << res%MOD << '\n';
}