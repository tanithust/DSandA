#include <iostream>
#include <cmath>
using namespace std;
long long result[100];
long long C(int n, int k, int m)
{
    long long c[101][101];
    for (int i = 0; i <= n; i++)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++)
        {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % m;
        }
    }
    return c[n][k];
}
int main()
{
    int test, n, k, m;
    cin >> test;
    for (int i = 1; i <= test; i++)
    {
        cin >> n >> k >> m;
        result[i] = C(n, k, m);
    }
    for (int i = 1; i <= test; i++)
    {
        cout << result[i] << endl;
    }
}