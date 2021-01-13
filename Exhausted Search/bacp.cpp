#include <bits/stdc++.h>
using namespace std;

int m, n;
int c[17];
int a[17][17];
int x[17];
int totalCredit[6];
int bestConfig = INT_MAX;

bool check(int v, int k)
{
    for (int i = 0; i < k; i++)
    {
        if (a[i][k] == 1 && x[i] >= v)
            return false;
        if (a[k][i] == 1 && v >= x[i])
            return false;
    }
    return true;
}
void bacp(int k)
{
    for (int i = 0; i < m; i++)
    {
        if (check(i, k))
        {
            x[k] = i;
            totalCredit[i] += c[k];
            if (k == n)
            {
                int mx = 0;
                for (int j = 0; j < m; j++)
                {
                    mx = max(mx, totalCredit[j]);
                }
                bestConfig = min(mx, bestConfig);
            }
            else
                bacp(k + 1);
            totalCredit[i] -= c[k];
        }
    }
}

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    bacp(0);
    cout << bestConfig;
}