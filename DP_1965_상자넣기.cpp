#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int d[1001];
int arr[1001];

int main(){
    int n;
    cin >> n;
    
    fill(d, d+n, 1);

    for(int i = 0; i<n; i++)
        cin >> arr[i];

    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[j] < arr[i]){
                d[i] = max(d[i], d[j]+1); //arr = [1, 2, 3, 1, 4] 
            }
        }
    }

    int res = 0;

    for(int i=0; i<n; i++){
        res = max(res, d[i]);
    }
    cout << res << endl;
}

//arr = [1, 2, 3, 1, 4] 
/* i = 0
 -> x

i = 1, j=0
d[1] = max(d[1], d[0]+1) = max(1,2) = 2

i=2 j=0
d[2] = max(d[2],d[0]+1) = max(1,2) = 2
i=2 j=1
d[2] = max(d[2], d[1]+1) = max(2,3) = 3


i=3
d[3] = 1

i=4
i=4, j=0
d[4] = max(d[4], d[0]+1) = max(1,2) = 2

i=4 j=1
d[4] = max(d[4], d[1]+1) = max(2,3) = 3

i=4 j=2
d[4] = max(d[4], d[2]+1) = max(3,4) = 4

i=4 j=3
d[4] = max(d[4], d[3]+1) = max(4,2) = 4 // V

-> 이에 따라 d[4] = 4가 된다.


*/