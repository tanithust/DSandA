#include <bits/stdc++.h>
using namespace std;
int n;
struct period
{
    int s, t;
} p[(int)2e6 + 5];
bool cmp(period a, period b)
{
    return a.t < b.t;
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    int smax = 0, tmax = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].s >> p[i].t;
        tmax = max(tmax, p[i].t);
        smax = max(smax, p[i].s);
    }
    vector<int> sp(smax + 1, 0), tp(tmax + 1, 0);
    // sp[i] dedicate for the max C from start time i
    // tp[i] dedicate for the max C before terminate time i
    for (int i = 0; i < n; i++)
    {
        int s = p[i].s, t = p[i].t;
        sp[s] = max(sp[s], t - s);
        tp[t] = max(tp[t], t - s);
    }
    for (int i = smax - 1; i >= 0; i--)
    {
        sp[i] = max(sp[i], sp[i + 1]);
    }
    for (int i = 1; i <= tmax; i++)
    {
        tp[i] = max(tp[i], tp[i - 1]);
    }
    int ans = -1;
    for (int i = 1; i <= smax; i++)
    {
        int a = tp[i - 1], b = sp[i];
        if (a == 0 || b == 0)
            continue;
        ans = max(a + b, ans);
    }
    cout << ans;
}
