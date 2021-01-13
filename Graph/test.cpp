#include <bits/stdc++.h>
using namespace std;
#define MAX (int)5e3 + 10
vector<int> p[MAX];
int n, k;
int c[MAX], d[MAX], cost[MAX][MAX];
int deg[MAX][MAX];
int vis[MAX];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i] >> d[i];
        for (int j = 1; j <= n; j++)
        {
            cost[i][j] = INT_MAX;
            deg[i][j] = 0;
        }
    }
    for (int i = 1; i <= k; i++)
    {
        int u, v;
        cin >> u >> v;
        p[u].push_back(v);
        p[v].push_back(u);
    }
    queue<int> q1;
    for (int i = 1; i <= n; i++)
    {
        cost[i][i] = 0;
        while (!q1.empty())
            q1.pop();
        deg[i][i] = 1;
        q1.push(i);
        while (!q1.empty())
        {
            int x = q1.front();
            q1.pop();
            if (deg[x][i] == 1 + d[i])
                continue;
            for (auto y : p[x])
            {
                if (deg[y][i] == 0)
                {
                    deg[y][i] = deg[x][i] + 1;
                    cost[i][y] = c[i];
                    q1.push(y);
                    //cout << '.' <<endl;
                }
            }
        }
    }
    priority_queue<pair<int, int>> q;
    vector<int> dis(n + 1, INT_MAX);
    int s = 1, t = n;
    dis[s] = 0;
    q.push({dis[s], s});
    while (!q.empty())
    {
        int b = q.top().second;
        q.pop();
        if (vis[b])
            continue;
        vis[b] = 1;
        for (int i = 1; i <= n; i++)
        {
            if (cost[b][i] != INT_MAX && dis[i] > dis[b] + cost[b][i])
            {
                dis[i] = dis[b] + cost[b][i];
                q.push({-dis[i], i});
            }
        }
    }
    cout << dis[t];
}