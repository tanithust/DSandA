#include <bits/stdc++.h>
using namespace std;
long long m, n, a, b, c;
struct edge
{
    long long u, v, w;
    edge(long long _u, long long _v, long long _w)
    {
        u = _u;
        v = _v;
        w = _w;
    }
};
vector<edge> adj;
long long p[100001];
long long find(long long x)
{
    if (p[x] == x)
        return x;
    else
    {
        p[x] = find(p[x]);
        return p[x];
    }
}
void unite(long long x, long long y)
{
    p[find(x)] = find(y);
}
bool edge_cmp(const edge &x, const edge &y)
{
    return x.w < y.w;
}
long long mst(long long n, vector<edge> edges)
{
    long long weight = 0;
    sort(edges.begin(), edges.end(), edge_cmp);
    for (auto i : edges)
    {
        long long u = i.u;
        long long v = i.v;
        if (find(u) != find(v))
        {
            unite(u, v);
            weight += i.w;
        }
    }
    return weight;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (long long i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        adj.push_back(edge(a, b, c));
    }
    for (long long i = 1; i <= n; i++)
        p[i] = i;
    long long ans = mst(n, adj);
    if (ans == 0)
        cout << -1;
    else
        cout << ans;
}