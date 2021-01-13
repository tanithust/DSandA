#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100001];
int m, n, a, b, t = 0, cnt = 0;
int v[100001], disc[100001], low[100001];
int connect[100001];
stack<int> comp;
void dfs(int x, int p)
{
    comp.push(x);
    low[x] = disc[x] = ++t;
    connect[x] = 1;
    for (int i : adj[x])
    {
        if (i == p)
            continue;
        if (!disc[i])
        {
            dfs(i, x);
            low[x] = min(low[x], low[i]);
        }
        else if (connect[i])
            low[x] = min(low[x], disc[i]);
    }
    if (low[x] == disc[x])
    {
        cnt++;
        while (true)
        {
            int cur = comp.top();
            comp.pop();
            connect[cur] = 0;
            if (cur == x)
                break;
        }
    }
}
void SCCdfs()
{
    for (int i = 1; i <= n; i++)
        if (!disc[i])
        {
            dfs(i, i);
        }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
    }
    memset(disc, 0, 100001);
    memset(low, 0, 100001);
    memset(connect, 0, 100001);
    SCCdfs();
    // for (int i = 1; i <= n; i++)
    //     cout << low[i] << " ";
    cout << cnt;
}