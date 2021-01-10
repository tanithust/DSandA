#include <bits/stdc++.h>
using namespace std;
int n,v[10000],w[10000],m;
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 0; i < n; i++) cin >> w[i];
    int ans[100][100];
    for(int i = 0; i < m; i++) ans[0][i] = 0;
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= m; j++){
            if( j < w[i-1]) ans[i][j] = ans[i-1][j];
            else ans[i][j] = max(ans[i-1][j],ans[i-1][j-w[i-1]]+v[i-1]);   
        }
    }
    cout << ans[n][m];
}