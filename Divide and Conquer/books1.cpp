#include <bits/stdc++.h>
using namespace std;
#define ma 501
typedef long long ll;

ll k, n;
ll p[ma];
ll separate[ma], ans[ma];
ll findma(ll p[], ll s)
{
    ll x = 0;
    for (ll i = 0; i < s; i++)
        x = max(p[i], x);
    return x;
}
ll fsum(ll p[], ll s)
{
    ll sum = 0;
    for (ll i = 0; i < s; i++)
        sum += p[i];
    return sum;
}
void reset(ll x, ll y)
{
    ll sum = 0;
    for (ll i = separate[x + 1] - 1; i >= separate[x]; i--)
    {
        sum += p[i];
        if (sum == y)
        {
            separate[x] = i;
            break;
        }
        else if (sum > y)
        {
            separate[x] = i + 1;
            break;
        }
    }
}
bool check(ll x)
{
    for (ll i = 0; i < k; i++)
        separate[i] = i;
    separate[k] = n;
    for (ll i = k - 1; i >= 0; i--)
        reset(i, x);
    if (separate[0] > 0)
        return false;
    return true;
}
void solve()
{
    cin >> n >> k;
    for (ll i = 0; i < n; i++)
        cin >> p[i];
    ll high = fsum(p, n), low = findma(p, n), mid;
    while (low < high)
    {
        mid = (high + low) / 2;
        if (check(mid))
        {
            high = mid;
            for (ll i = 0; i < k; i++)
                ans[i] = separate[i];
        }
        else
            low = mid + 1;
    }
    for (ll i = 0; i < k - 1; i++)
    {
        for (ll j = ans[i]; j < ans[i + 1]; j++)
            cout << p[j] << " ";
        cout << "/ ";
    }
    for (ll i = ans[k - 1]; i < n; i++)
    {
        cout << p[i];
        if (i == n - 1)
            break;
        cout << " ";
    }
    cout << endl;
}

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}