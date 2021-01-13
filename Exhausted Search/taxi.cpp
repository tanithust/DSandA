#include <bits/stdc++.h>
using namespace std;

int n; 
int dis[23][23];
int x[23];
int visited[23];
int totalDis = 0;
int carry = 0;
int sRoute = INT_MAX,cmin = INT_MAX;

bool check(int i){
    if(visited[i]) return false;
    if(i > n && !visited[i-n]) return false;
    else if(i <= n && carry >= 1) return false;
    return true;
}

void taxi(int k){
    for(int i = 1; i <= 2*n; i++){
        if(check(i)){
            x[k] = i;
            totalDis += dis[x[k-1]][i];
            if(i >n) carry--;
            else carry++;
            visited[i] = true;
            if(k == 2*n){
                sRoute = min(sRoute,totalDis + dis[x[k]][0]);
            }
            else if(totalDis + (2*n+1-k)*cmin < sRoute){
                taxi(k+1);
            }
            visited[i] = false;
            if(i >n) carry++; else carry--;
            totalDis -= dis[x[k-1]][i];
        }
    }
}
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i <= 2*n; i++){
        for(int  j = 0; j <= 2*n; j++) {
            cin >> dis[i][j];
            if(i !=j ) cmin = min(cmin, dis[i][j]);
        }
    }
    for(int i = 0 ; i < 2*n; i++) visited[i] =0;
    taxi(1);
    cout << sRoute;
}