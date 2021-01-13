#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> period;
long long n;
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int mst, mtt;
    for (long long i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        period.push_back(make_pair(a, b));
        mst = max(mst, a);
        mtt = max(mtt, b);
    }
    vector<int> smc(mst + 1, 0), tmc(mtt + 1, 0);
    for (int i = 0; i < n; i++)
    {
        int start = period[i].first, end = period[i].second;
        smc[start] = max(smc[start], end - start);
        tmc[end] = max(tmc[start], end - start);
    }
    for (int i = mst - 1; i >= 0; i--)
    {
        smc[i] = max(smc[i], smc[i + 1]);
    }
    for (int i = 1; i <= mtt; i++)
    {
        tmc[i] = max(tmc[i], tmc[i - 1]);
    }
    int res = -1;
    for (int i = 1; i <= mst; i++)
    {
        if (smc[i] == 0 || tmc[i - 1] == 0)
            continue;
        else
            res = max(res, smc[i] + tmc[i - 1]);
    }
    cout << res;
}