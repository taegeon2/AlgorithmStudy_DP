#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 10007

ll dp[1001][11]; // dp[i][j] => 길이가 i이면서 끝 자리 수가 j인 수의 개수

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for(int i=0; i<=9; i++)
        dp[1][i] = 1;

    for(int i=2; i<=1000; i++){
        for(int j=0; j<=9; j++){
            for(int k=0; k<=j; k++){
                dp[i][j] +=dp[i-1][k] % MOD;
            }
        }
    }

    ll res  = 0;
    for(int i=0; i<=9; i++){
        res += dp[n][i];
    }
    cout << res%MOD << '\n';
}