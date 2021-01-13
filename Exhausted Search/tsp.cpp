#include <bits/stdc++.h>
using namespace std;
long long m,n,cmin = INT_MAX;
long long a,b,c;
long long cost[21][21];
long long totalCost[100],x[100];
int visited[21];
int bestConfig = INT_MAX;

void initialize(){
    for(int i = 1; i <= n; i++ ){
        visited[i] = false;
        x[i] = 1;
        totalCost[i] = 0;
    }
    visited[1] = true;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n;j++) cost[i][j] = 0;
    }
}

void TRY(int k){
    for(int i = 2;i <= n; i++ ){
        if(!visited[i] && cost[x[k-1]][i] != 0){
            x[k] = i;
            totalCost[k] = totalCost[k-1] + cost[x[k-1]][x[k]];
            if(totalCost[k] < bestConfig){
                if(k < n ){
                    visited[i] = true;
                    TRY(k+1);
                    visited[i] = false;
                }
                else{
                    if(totalCost[k] + cost[x[k]][1] < bestConfig && cost[x[k]][1] != 0){
                        bestConfig = totalCost[k] + cost[x[k]][1]; 
                    }
                }
            }
        }
    }
}

int main(){
    cin >> n >> m;
    initialize();
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        cost[a][b] = c;
        cmin = min(cmin,c);
    }
    TRY(2);
    if(bestConfig == INT_MAX){
        cout << -1;
        return 1;
    }
    cout << bestConfig;
}