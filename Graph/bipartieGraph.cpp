#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100001];
int l[100001];
long long m, n, a, b;
int bfs(int x)
{
    queue<int> q;
    q.push(x);
    l[x] = 0;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int i : adj[v])
        {
            if (l[i] > -1)
            {
                if (l[i] % 2 == l[v] % 2)
                    return 0;
            }
            else
            {
                l[i] = l[v] + 1;
                q.push(i);
            }
        }
    }
    return 1;
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
    for (int i = 1; i <= n; i++)
        l[i] = -1;
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        if (l[i] == -1)
        {
            if (!bfs(i))
            {
                ans = 0;
                break;
            }
        }
    }
    cout << ans;
}