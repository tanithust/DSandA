#include <bits/stdc++.h>
using namespace std;
int m, n, a, b, t;
vector<int> adj[100001];
int l[100001];
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
void clr()
{
    for (int i = 1; i <= n; i++)
        adj[i].clear();
    memset(l, 0, 100001);
}
int solve()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
        l[i] = -1;
    for (int i = 1; i <= n; i++)
    {
        if (l[i] == -1)
        {
            if (!bfs(i))
            {
                clr();
                return 0;
            }
        }
    }
    clr();
    return 1;
}

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    int i = 1;
    cin >> t;
    while (t--)
    {
        if (solve() == 0)
            cout << "Scenario #" << i << ":" << endl
                 << "Suspicious bugs found!" << endl;
        else
            cout << "Scenario #" << i << ":" << endl
                 << "No suspicious bugs found!" << endl;
        i++;
    }
}