#include <bits/stdc++.h>
using namespace std;
long long m, n;
long long arr[1000000];
bool check(int x)
{
    int cut = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] - x > 0)
            cut += arr[i] - x;
        if (cut >= m)
            return true;
    }
    return false;
}
void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    long long low = arr[0], high = arr[n - 1], mid, ans;
    while (low <= high)
    {
        mid = (high + low) / 2;
        if (check(mid))
        {
            low = mid + 1;
            ans = mid;
        }
        else
            high = mid - 1;
    }
    cout << ans;
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}