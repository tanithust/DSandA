#include <bits/stdc++.h>
using namespace std;
int a[1000000], m[1000000][50];
long long n, c, b, p;
int log(long long x, long long y)
{
    long long t = y - x + 1;
    if (t < 1 << 1)
        return 1;
    else if (t < 1 << 2)
        return 1;
    else if (t < 1 << 3)
        return 2;
    else if (t < 1 << 4)
        return 3;
    else if (t < 1 << 5)
        return 4;
    else if (t < 1 << 6)
        return 5;
    else if (t < 1 << 7)
        return 6;
    else if (t < 1 << 8)
        return 7;
    else if (t < 1 << 9)
        return 8;
    else if (t < 1 << 10)
        return 9;
    else if (t < 1 << 11)
        return 10;
    else if (t < 1 << 12)
        return 11;
    else if (t < 1 << 13)
        return 12;
    else if (t < 1 << 14)
        return 13;
    else if (t < 1 << 15)
        return 14;
    else if (t < 1 << 16)
        return 15;
    else if (t < 1 << 17)
        return 16;
    else
        return 17;
}
void ini()
{
    long long i, j;
    for (i = 0; i < n; i++)
        m[i][0] = a[i];
    for (j = 1; (1 << j) <= n; j++)
    {
        for (i = 0; i + (1 << j) - 1 < n; i++)
        {
            if (m[i][j - 1] < m[i + (1 << (j - 1))][j - 1])
                m[i][j] = m[i][j - 1];
            else
                m[i][j] = m[i + (1 << (j - 1))][j - 1];
        }
    }
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (long long i = 0; i < n; i++)
        cin >> a[i];
    ini();
    cin >> p;
    unsigned long long s = 0;
    for (long long i = 0; i < p; i++)
    {
        cin >> c >> b;
        int k = log(c, b);
        s += min(m[c][k], m[b - (1 << k) + 1][k]);
    }
    cout << s;
}