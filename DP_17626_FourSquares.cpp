#include <bits/stdc++.h>
using namespace std;

int n;
int dp[50001];


void showArr(){
    for(int i=1; i<=n; i++){
        cout << dp[i] << ' ';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 2;

    for(int i = 1; i<=n; i++){
        for(int j=4; j*j<=i; j++){
            dp[j] = min(dp[j], dp[j]);
        }
    }


    //showArr();

    cout << dp[n] << '\n';
}
