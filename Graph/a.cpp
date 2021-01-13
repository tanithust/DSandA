#include <bits/stdc++.h>
using namespace std;
struct town
{
    int x,trv;
};

int m, n, a, b;
int c[100001], d[100001];
vector<int> adj[100001];
vector<int> net[100001];
void bfs(int s){
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int i : adj[v]){
            
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i] >> d[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}