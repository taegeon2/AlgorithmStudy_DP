#include <bits/stdc++.h>
using namespace std;

int dp[1001]; // dp[i] => i번째 값을 마지막으로 하는 가장 큰 부분수열
int arr[1001];

int main(){
    int n;
    cin >> n;

    for(int i=0; i<n; i++)
        cin >> arr[i];

    int sum =0;

    for(int i=0; i<n; i++)
        dp[i] = arr[i];

    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[j] < arr[i]){
                dp[i] = max(dp[i], dp[j] + arr[i]);
                //dp[i] = dp[j] + arr[i];
            }
            cout << "   i :" << i;
            cout << "   j :" << j;
            cout << "   dp[i] :" << dp[i];
            cout << "       dp[j] :" << dp[j];
            cout << "   arr[i] :" << arr[i];
            cout << "\n";
        }
    }

    int res = 0;
    for(int i=0; i<n; i++)
        res = max(res, dp[i]);
    
    cout << res << '\n';
}