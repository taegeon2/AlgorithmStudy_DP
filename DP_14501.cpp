#include <bits/stdc++.h>
using namespace std;

int T[16], P[16], dp[17];
//dp[i]: i번째 날부터 N일까지 일했을 때 얻는 최대 이윤
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int day;
    cin >> day;
    for (int i = 1; i <= day; i++) {
        cin >> T[i] >> P[i];
    }

    for(int i=day; i>=1; i--){
        if(i+T[i]-1 <=day){ // if문에 들어온다 == i번째날의 일을 할 수 있다.
            dp[i] = max(dp[i + T[i]] + P[i], dp[i+1]);
        }
        else
            dp[i] = dp[i+1]; // i번째 날에 어차피 일 못하니 다음 인덱스로 넘기기
    }

    cout << dp[1] << '\n';
}