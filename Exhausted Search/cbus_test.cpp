#include <bits/stdc++.h>
using namespace std;
int n,cap = 2,load = 0;
int dis[23][23],x[100],visited[100],totalDis;
int sRoute = INT_MAX;
int bestRoute[23];
void inititalize(){
    for(int i = 1; i <= 2*n;i++){
        visited[i] = false;
        x[i] = 0;
    }
    visited[0] = true;
}
bool check(int i){
    if(visited[i]) return false;
    if(i > n && !visited[i-n]) return false;
    if(i <= n && load + 1 > cap) return false;
    return true;  
}
void TRY(int k){
    for(int i = 1; i < 2*n+1; i++){ 
        if(check(i)){
            x[k] = i;
            totalDis += dis[x[k-1]][i];
            if(i <= n) load ++; else load--;
            if(totalDis < sRoute){
                if(k < 2*n){
                    visited[i] = true;
                    TRY(k+1);
                }
                else{   
                    if(sRoute > totalDis + dis[x[k]][0]){
                        sRoute = totalDis + dis[x[k]][0];
                        for(int i = 0 ; i <= 2*n; i++) bestRoute[i] = x[i];
                    }
                }
            }
            totalDis -= dis[x[k-1]][i];
            if(i <= n) load --; else load++;
            visited[i] = false;
        }
    }
}
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> cap;
    for(int i = 0; i < 2*n+1; i++){
        for(int j = 0; j < 2*n+1; j++) cin >> dis[i][j];
    }   
    inititalize();
    TRY(1);
    if(sRoute == INT_MAX) {
        cout << -1 << " ";
        return 1;
    }
    cout << sRoute;
    //for(int i = 0; i < 2*n+1;i++) cout <<bestRoute[i]<<" "<< bestRoute[i+1] <<" "<<dis[bestRoute[i]][bestRoute[i+1]]<<endl;
    
}