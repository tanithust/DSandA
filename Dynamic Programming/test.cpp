#include <bits/stdc++.h>
using namespace std;
int tg[1001], a[1001];
int n, t, d;
int total[1001][101]; //total[i][j] the total amount of goods the truck picked untgl point i with the tgme j
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> t >> d;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> tg[i];
    for (int i = 0; i <= t; i++)
    {
        if (i != tg[0])
            total[0][i] = 0;
        else
            total[0][i] = a[0];
    }
    for (int i = 1; i < n; i++)
    {
        for (int k = 0; k <= t; k++)
        {
            if (k != tg[i])
                total[i][k] = 0;
            else
                total[i][k] = a[i];
            for (int j = 1; j <= d; j++)
            {
                int x = i - j;
                if (x >= 0 && k >= tg[i] && total[x][k - tg[i]] > 0)
                    if (total[i][k] < total[x][k - tg[i]] + a[i])
                        total[i][k] = total[x][k - tg[i]] + a[i];
            }
        }
    }
    int rs = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= t; j++)
        {
            if (total[i][j] > rs)
                rs = total[i][j];
        }
    }
    cout << rs;
}