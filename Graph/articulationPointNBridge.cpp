#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100000];
int m, n, a, b, t, BRcnt = 0, APcnt = 0;
int disc[100001], low[100001], ap[100001];
int dfs(int u, int p)
{
    int children = 0;
    low[u] = disc[u] = ++t;
    for (int v : adj[u])
    {
        if (v == p)
            continue;
        if (!disc[v])
        {
            children++;
            dfs(v, u);
            if (disc[u] <= low[v])
            {
                ap[u] = 1;
                if (disc[u] < low[v])
                    BRcnt++;
            }
            low[u] = min(low[u], low[v]);
        }
        else
            low[u] = min(low[u], disc[v]);
    }
    return children;
}
void solve()
{
    t = 0;
    for (int u = 1; u <= n; u++)
        if (!disc[u])
            ap[u] = dfs(u, u) > 1;
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    solve();
    for (int i = 1; i <= n; i++)
        if (ap[i] == 1)
            APcnt++;
    cout << APcnt << " " << BRcnt;
}