#include <bits/stdc++.h>
using namespace std;
int m, n, a, b, c, s, t;
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
long long dist[100001];
void bfs()
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
            int v = i.v;
            int w = i.w;
            if (w + dist[x] < dist[v])
            {
                dist[v] = dist[x] + w;
                q.push(v);
            }
        }
    }
}

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        adj[a].push_back(edge(b, c));
    }
    cin >> s >> t;
    for (int i = 0; i <= n; i++)
        dist[i] = INT_MAX;
    bfs();
    if (dist[t] == INT_MAX)
        cout << -1;
    else
        cout << dist[t];
}