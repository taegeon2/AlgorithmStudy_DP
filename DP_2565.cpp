#include <bits/stdc++.h>
using namespace std;

int dp[101];
pair<int, int> lineArr[101];

int main(){
    int n;
    cin >> n;
    fill(dp,dp+n,1);

    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        lineArr[i] = {a,b};
    }

    sort(lineArr, lineArr+n);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(lineArr[i].second > lineArr[j].second){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }

    int longest  = 0;
    for(int i=0; i<n; i++){
        longest = max(longest, dp[i]);
    }
    
    //cout << "longest: " << longest << '\n';
    int res = n- longest;
    cout << res << '\n';
}