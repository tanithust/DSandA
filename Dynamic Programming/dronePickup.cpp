#include <bits/stdc++.h>
#define N 50000
#define oo 1000000000
using namespace std;
int f[5000][200];
int n, k, a[N], c[N], kq = -oo;
main()
{
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= k + 1; j++)
            f[i][j] = -oo;
    f[1][1] = c[1];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= k; j++)
        {
            for (int p = 1; p <= a[i]; p++)
            {
                f[i + p][j + 1] = max(f[i + p][j + 1], f[i][j] + c[i + p]);
            }
        }
    for (int i = 1; i <= k + 1; i++)
        kq = max(kq, f[n][i]);
    if (kq < 0)
        cout << -1;
    else
        cout << kq;
}