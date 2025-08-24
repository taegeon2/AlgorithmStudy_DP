#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll myDiv =  1'000'000'009;
ll num[1000001];

int main(){
    int t;
    cin >> t;
    
    num[1] = 1;
    num[2] = 2;
    num[3] = 4;

    for(int i=4; i<=1'000'000; i++){  // num [1'000'000]
        num[i] = (num[i-1] + num[i-2] + num[i-3]) % myDiv;
    }

    while(t--){
        int n;
        cin >> n;
        cout << num[n] << '\n';    
    }

}
