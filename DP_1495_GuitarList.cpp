#include <bits/stdc++.h>
using namespace std;
// https://www.acmicpc.net/problem/1495
int N, S, M;

int arr[51];
bool dp[51][1001]; //dp[i][j] => i번째 회차에서 가능한(0~j) 까지의 불륨

void PrintArr(){
    for(int i=0; i<=N; i++){
        for(int j=0; j<=M; j++){
            cout << dp[i][j] << " ";
        }
        cout << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> N >> S >> M;

    dp[0][S] = true; // 0회차일 시점에 불륨 S는 TRUE
    for(int i=1; i<=N; i++)
        cin >> arr[i];
    
    for(int i=1; i<=N; i++){
        for(int j=0; j<=1000; j++){
            if(dp[i-1][j]){
                if(j+arr[i] <= M && j+arr[i]>=0)
                    dp[i][j+arr[i]] = true;
                if(j-arr[i] <= M && j-arr[i]>=0)
                    dp[i][j-arr[i]] = true;
            }
        }
    }
    //PrintArr();

    int ans = -1;
    for(int i=0; i<=1000; i++){
        if(dp[N][i])
            ans = i;
    }
    cout << ans << '\n';
}
