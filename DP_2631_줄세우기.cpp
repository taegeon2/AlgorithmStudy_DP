#include <bits/stdc++.h>
using namespace std;

int arr[201];
int lis[201];
int cnt;

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];

    fill(lis, lis+n, 1);

    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[j] < arr[i]){
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
    }

    int maxIncrease = 0;
    
    for(int i=0; i<n; i++){
        if(lis[i] > maxIncrease)
            maxIncrease = lis[i];
    }

    cout << n-maxIncrease << '\n';
}