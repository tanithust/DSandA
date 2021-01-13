#include <bits/stdc++.h>
using namespace std;
int t, n, c;
long long arr[100001];
bool check(int x)
{
    int cow_placed = 1, las_pos = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - arr[las_pos] >= x)
        {
            if (++cow_placed == c)
                return true;
            las_pos = i;
        }
    }
    return false;
}
void solve()
{
    cin >> n >> c;
    for (int j = 0; j < n; j++)
        cin >> arr[j];
    sort(arr, arr + n);
    //binary search
    long long low = 0, high = 1000000000, mid, pos = 0;
    while (high >= low)
    {
        mid = (high + low) / 2;
        if (check(mid))
        {
            low = mid + 1;
            pos = mid;
        }
        else
            high = mid - 1;
    }
    cout << pos << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
        solve();
}