#include <bits/stdc++.h>
using namespace std;
int f, s, g, u, d;
int v[1000001];
struct fl
{
    int floor, cnt;
};
int bfs()
{
    int ans = 0;
    queue<fl> q;
    fl curFl, nextFl;
    curFl = (fl){s, 0};
    q.push(curFl);
    v[s] = 1;
    while (!q.empty())
    {
        curFl = q.front();
        q.pop();
        for (int i = 0; i < 2; i++)
        {
            if (i == 0)
            {
                nextFl.floor = curFl.floor + u;
            }
            if (i == 1)
            {
                nextFl.floor = curFl.floor - d;
            }
            if (nextFl.floor < 1 || nextFl.floor > f)
                continue;
            if (!v[nextFl.floor])
            {
                v[nextFl.floor] = 1;
                nextFl.cnt = curFl.cnt + 1;
                q.push(nextFl);
                if (nextFl.floor == g)
                {
                    ans = nextFl.cnt;
                    return ans;
                }
            }
        }
    }
    return ans;
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cin >> f >> s >> g >> u >> d;
    if (s == g)
    {
        cout << 0;
        return 0;
    }
    for (int i = 1; i <= f; i++)
        v[i] = 0;
    int res = bfs();
    if (res == 0)
        cout << "use the stairs";
    else
        cout << res;
}