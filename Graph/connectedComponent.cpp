#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100000];
int visited[100001];
long long m, n, a, b, cnt = 0;
void dfs(long long x)
{
    if (visited[x] == 0)
    {
        visited[x] = 1;
        for (int i : adj[x])
        {
            dfs(i);
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
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
        visited[i] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            cnt++;
            dfs(i);
        }
    }
    cout << cnt;
}