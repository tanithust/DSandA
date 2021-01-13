#include <bits/stdc++.h>
using namespace std;
int m, n, k, a, b;
vector<int> adj[100001];
int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}