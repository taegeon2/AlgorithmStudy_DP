#include <bits/stdc++.h>
using namespace std;

int arr[1001];
int dp[1001]; //dp[i] -> i번째 원소값을 마지막으로 하는 가장 긴 감소수열 길이

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> arr[i];
        dp[i] = 1;
    }

    for(int i=0; i<t; i++){
        for(int j=0; j<i; j++){
            if(arr[j] > arr[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    
    int res = 0;
    for(int i=0; i<t; i++){
        res = max(res, dp[i]);
    }
    cout << res << '\n';
}