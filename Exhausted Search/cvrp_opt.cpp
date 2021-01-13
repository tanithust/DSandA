#include <bits/stdc++.h>
using namespace std;

int k,n,capacity;
int d[12];
int dis[13][13];
int x[100];
int visited[13];
int totalDis = 0,sRoute = INT_MAX,currentLoad,minLoad = INT_MAX;

bool check(int i){
    if(visited[i]) return false;
    if(currentLoad < d[i]) return false;
    return true;
}
bool isDone(){
    for(int i = 1; i <= n;i++){
        if(!visited[i]) return false;
    }
    return true;
}

void cvrp_otp(int k){
    for(int i = 1; i <= n; i++){
        if(check(i)){
                x[k] = i;
                totalDis += dis[x[k-1]][i];
                currentLoad -= d[i];
                visited[i] = true;
                if(isDone()){
                    sRoute = min(sRoute,totalDis + dis[x[k]][0]);
                }
                else{
                    cvrp_otp(k+1);
                }
                visited[i] =false;
                currentLoad += d[i];
                totalDis -= dis[x[k-1]][i];
        }
        else if(currentLoad < minLoad){
            x[k] = 0;
            totalDis += dis[x[k-1]][0];
            currentLoad = capacity;
            cvrp_otp(k+1);
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k >> capacity;
    for(int i = 0; i < n; i++ ) {
        cin >> d[i];
        minLoad = min(minLoad,d[i]);
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++)
            cin >> dis[i][j];
    }
    for(int i = 0; i <= n; i++) visited[i] = false;
    visited[0] = true;
    currentLoad = capacity;
    cvrp_otp(1);
    cout << sRoute;
}