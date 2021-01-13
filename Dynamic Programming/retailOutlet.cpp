#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
int n, m;
int a[101], s[101][501];
long long addmod(long long a, long long b)
{
    a = a % mod;
    b = b % mod;
    long long tmp = mod - b;
    if (tmp > a)
        return a + b;
    else
        return a - tmp;
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
    {
        if (i % a[1] == 0)
            s[1][i] = 1;
        else
            s[1][i] = 0;
    }
    for (int i = 2; i <= n; i++)
    {
        for (int k = 1; k <= m; k++)
        {
            s[i][k] = 0;
            int x = 0;
            for (int j = 1; j < i - 1; j++)
                x += a[j];
            x = (k - x) / a[i];
            for (int y = 1; y <= x; y++)
                if (k - a[i] * y > 0)
                    s[i][k] = addmod(s[i][k], s[i - 1][k - a[i] * y]);
        }
    }
    cout << s[n][m];
}