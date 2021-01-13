#include <bits/stdc++.h>
using namespace std;
int n, a, b, c;
int dist[100001];
struct edge
{
    int v, w;
    edge(int _v, int _w)
    {
        v = _v;
        w = _w;
    }
};
vector<edge> adj[100001];
void bfs(int s)
{
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (edge i : adj[x])
        {
            int w = i.w;
            int v = i.v;
            if (dist[v] > -1)
            {
                continue;
            }
            q.push(v);
            dist[v] = dist[x] + w;
        }
    }
}
int find()
{
    int mx = -1;
    int u;
    for (int i = 1; i <= n; i++)
    {
        if (mx < dist[i])
        {
            mx = dist[i];
            u = i;
        }
    }
    return u;
}
void setDist()
{
    for (int i = 1; i <= n; i++)
    {
        dist[i] = -1;
    }
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b >> c;
        adj[a].push_back(edge(b, c));
        adj[b].push_back(edge(a, c));
    }
    setDist();
    bfs(1);
    int u = find();
    setDist();
    bfs(u);
    cout << dist[find()];
}