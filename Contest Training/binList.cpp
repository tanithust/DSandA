#include <bits/stdc++.h>

using namespace std;
int n, k, i, a[500001], dem;
void dequy(int position, int s)
{
    if (position > n)
    {
        dem++;
        if (dem == k)
            for (int i = 1; i <= n; i++)
                cout << a[i] << " ";
        return;
    }
    if (dem > k)
        return;
    if (s < i - 1)
    {
        a[position] = 0;
        dequy(position + 1, s + 1);
    }
    a[position] = 1;
    dequy(position + 1, 0);
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k >> i;
    dequy(1, 0);
    if (dem < k)
        cout << -1;
}