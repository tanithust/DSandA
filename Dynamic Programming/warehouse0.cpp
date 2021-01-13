#include <iostream>
#define MAX_N 1001
#define MAX_T 101
#define MAX_D 11
#define MAX_VALUE 100
using namespace std;
int n;
int T;
int D;
int a[MAX_N];
int t[MAX_N];
int S[MAX_N][MAX_T]; // S[i][t] max amount of goods 0 picked up
// until point i, total pickup time = t
int rs;
void input()
{
    cin >> n >> T >> D;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> t[i];
}
void solve()
{
    for (int k = 0; k <= T; k++)
    {
        if (k != t[0])
            S[0][k] = 0;
        else
            S[0][k] = a[0];
    }
    for (int i = 1; i < n; i++)
    {
        for (int k = 0; k <= T; k++)
        {
            if (k != t[i])
                S[i][k] = 0;
            else
                S[i][k] = a[i];
            for (int d = 1; d <= D; d++)
            {
                int j = i - d;
                if (j >= 0 && k >= t[i] && S[j][k - t[i]] > 0)
                    if (S[i][k] < S[j][k - t[i]] + a[i])
                        S[i][k] = S[j][k - t[i]] + a[i];
            }
        }
    }
    rs = 0;
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k <= T; k++)
        {
            if (S[i][k] > rs)
                rs = S[i][k];
        }
    }
    cout << rs;
}
int main()
{
    input();
    solve();
}