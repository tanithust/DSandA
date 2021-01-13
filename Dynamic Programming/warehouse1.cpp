#include <bits/stdc++.h>
#define vc 100000
using namespace std;
int g[1001],tg[1001];

int main(){
    int n,t,d;
    cin >> n >> t >> d;
    for(int i = 1; i <= n; i++) cin >> g[i];
    for(int i = 1; i <= n; i++) cin >> tg[i];
    int picked[1001][100];
    for(int i = 0; i <= n; i++){
        for(int j = 0;j <= t; j++){
            picked[i][j] = -vc;
        }
    }
    picked[1][tg[1]]=g[1];
    for(int i = 2; i <= n; i++){       
        for(int k = 1; k <= d && i - k > 0; k++){
            for(int j = tg[1]; j <=t; j++){ 
                if(picked[i-k][j-tg[i]] < 0 || j < tg[i]) continue;
                else picked[i][j] = max(picked[i-k][j-tg[i]]+g[i],picked[i][j]);
            }
        }
    }
    int m=0;
    for(int i = 1; i <= n; i++){
        for(int j =1; j <=t;j++){
            m =max(m,picked[i][j]);
        }
    } 
    cout << m ;
}