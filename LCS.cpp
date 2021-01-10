#include <bits/stdc++.h>
using namespace std;

int max(int a, int b);

int lcs(int X[], int Y[], int m, int n)
{
    int L[m + 1][n + 1];
    int i, j;
    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;

            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;

            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    return L[m][n];
}
int max(int a, int b)
{
    return (a > b) ? a : b;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int X[1000000], Y[1000000];
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        cin >> X[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> Y[i];
    }
    cout << lcs(X, Y, m, n);

    return 0;
}