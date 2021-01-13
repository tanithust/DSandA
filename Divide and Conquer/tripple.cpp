#include <bits/stdc++.h>
using namespace std;
int n, k;
long long arr[5000];
int cnt = 0;
void solve()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    int l, r;
    for (int i = 0; i < n - 2; i++)
    {
        l = i + 1;
        r = n - 1;
        while (l < r)
        {
            if (arr[i] + arr[l] + arr[r] == k)
            {
                cnt++;
                l++;
                r--;
            }
            else if (arr[i] + arr[l] + arr[r] < k)
                l++;
            else if (arr[i] + arr[l] + arr[r] > k)
                r--;
        }
    }
    cout << cnt;
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
