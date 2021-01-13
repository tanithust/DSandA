#include <bits/stdc++.h>
using namespace std;
int n, k1, k2;
void solve()
{
    int s0[2000], s1[2000];
    for (int i = 1; i <= n; i++)
    {
        s0[i] = 0;
        s1[i] = 0;
    }
    s0[1] = 1;
    s1[k1] = 1;
    s0[0] = 1;
    for (int i = k1 + 1; i <= n; i++)
    {
        s0[i] = s1[i - 1];
        s1[i] = 0;
        for (int j = k1; j <= k2; j++)
        {
            if (i - j >= 0)
                s1[i] += s0[i - j];
        }
    }
    int res = s0[n] + s1[n];
    cout << res;
}
int main()
{
    cin >> n >> k1 >> k2;
    solve();
}