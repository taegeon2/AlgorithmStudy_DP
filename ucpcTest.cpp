#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll wall[200001];
int N, Q, cmd;

void EnforceWall(ll wallNum, ll noise){
    ll leftWallNum = wallNum;
    ll rightWallNum = wallNum+1;
    ll leftNoise = noise;
    ll rightNoise = noise;

    while(leftNoise > 0 && leftWallNum >=1 && leftWallNum <=N){
        if(leftNoise <= wall[leftWallNum]){
            wall[leftWallNum] += leftNoise;
            leftNoise -= wall[leftWallNum];
            leftWallNum --;
        }
        else{
            wall[leftWallNum] += wall[leftWallNum];
            leftNoise -= wall[leftWallNum];    
        }      
    }

    while(rightNoise > 0 && rightWallNum >=1 && rightWallNum <=N){
        if(rightNoise <= wall[rightWallNum]){
            wall[rightWallNum] += rightNoise;
            rightNoise -= wall[rightWallNum];
            rightWallNum ++;
        }
        else{
            wall[rightWallNum] += wall[rightWallNum];
            rightNoise -= wall[rightWallNum];    
        }      
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> N;
    for(int i=1; i<=N; i++)
        cin >> wall[i];
    
    cin >> Q;

    while(Q--){
        cin >> cmd ;
        if(cmd == 1){
            ll wallNum, noise;
            cin >> wallNum >> noise;
            EnforceWall(wallNum, noise);
        }
        else if(cmd == 2){
            int wallNum;
            cin >> wallNum;
            cout << wall[wallNum] << '\n'; 
        }
    }
}
