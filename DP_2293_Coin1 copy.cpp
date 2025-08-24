#include <bits/stdc++.h>
using namespace std;

int arr[101];
int dp[101][10001];

int n, k;
void ShowArr(){
    for (int item = 0; item <= n; item++)
    {
        cout << "   item : " << item;
        cout << ")   ";
        for (int j = 0; j <= k; j++)
        {
            cout << dp[item][j] << "    ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n >> k;

    for(int i=0; i<n; i++){
        cin >> arr[i+1];
    }
    dp[0][0] = 1;
    
    for(int item=1; item<n; item++){
        int curVal = arr[item];
        for(int dollar=0; dollar<=k; dollar++){
            dp[item][dollar] += dp[item-1][dollar];
            dp[item][dollar] += dp[item-1][dollar-curVal];
        }
    }

    ShowArr();
    cout << dp[n][k] << "\n";
}