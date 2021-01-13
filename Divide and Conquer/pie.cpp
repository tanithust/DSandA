#include <bits/stdc++.h>
#define pi 3.141592654
using namespace std;
int t, n, f, s[100000];
bool check(double x)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cnt += (int)floor(s[i] / x);
        if (cnt > f)
            return true;
    }
    return false;
}
void solve()
{
    cin >> n >> f;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        s[i] *= s[i];
    }
    double low = 0, high = 100000000.0, mid;
    while (low + 1e-7 < high)
    {
        mid = (high + low) / 2;
        if (check(mid))
            low = mid;
        else
            high = mid;
    }
    cout << setprecision(6) << fixed << low * pi << endl;
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
        solve();
    return 0;
}