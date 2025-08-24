#include <bits/stdc++.h>
using namespace std;

int arr[101];
int dp[10001];

int n, k;
void ShowArr(){
    for(int i=1; i<=k; i++){
        cout << dp[i] << '\n';
    }
}//

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> k;

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    dp[0] = 1;
    
    for(int i=0; i<n; i++){
        int curVal = arr[i];
        for(int j=curVal; j<=k; j++){
            dp[j] += dp[j-curVal];
        }
    }

    ShowArr();
    //cout << dp[k] << "\n";
}