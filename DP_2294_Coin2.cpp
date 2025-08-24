#include <bits/stdc++.h>
using namespace std;
#define SIZE 10000001

int n, k;
int dp[SIZE];
int arr[101];


void showArr(){
    for(int i=0; i<=k; i++){
        cout << dp[i] << ' ';
    }
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    fill(dp, dp+SIZE, SIZE);
    cin >> n >> k;

    for(int i=0; i<n; i++){
        cin >> arr[i];
        dp[arr[i]] = 1;
    }

    for(int i=0; i<n; i++){
        int curVal = arr[i];
        for(int j=curVal; j<=k; j++){
            dp[j] = min(dp[j], dp[j-curVal]+1); 
        }
    }

    for(int i=0; i<=k; i++){
        if(dp[i] == SIZE)
            dp[i] = -1;
    }
    //showArr();
    cout << dp[k];
}