#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(){
    vector<int> adj[100001];
    int nod,a,b,ans = 0;
    cin >> nod;
    for(int i = 1;i < nod; i++ ){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 2; i <= nod; i++){
        if (adj[i].size() == 1) ans++;
    }
    cout << ans;
}