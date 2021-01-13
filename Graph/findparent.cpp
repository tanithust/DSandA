#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(){
    ios_base:: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); 
    vector<int> s;
    vector <int> adj[100001];
    int v,p[100000],x,a,b;
    cin >> x;
    for(int i = 1; i <= x-1; i++){
        cin >> a >> b;
        adj[a].push_back(b);
		adj[b].push_back(a);
    }
    for(int i = 1; i <= x; i++) p[i] = -1;
    p[1] = 0;
    s.push_back(1);
    while(!s.empty()){
        v = s.back();
        s.pop_back();
        for(int j : adj[v]){
            if(p[j] == -1) {
                p[j] = v;
                s.push_back(j);   
            }
        }
    }
    for(int i = 2; i <= x; i++) cout << p[i] << " ";
}