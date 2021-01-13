#include <bits/stdc++.h>
using namespace std;
long long n, c;
long long pos[100001];

void input()
{
    cin >> n >> c;
    for (int i = 0; i < n; i++)
        cin >> pos[i];
    sort(pos, pos + n);
}
bool check(int x)
{
    int cows = 1, last = pos[0];
    for (int i = 1; i < n; i++)
    {
        if (pos[i] - last >= x)
        {
            cows++;
            last = pos[i];
            if (cows == c)
                return true;
        }
    }
    return false;
}
void solve()
{
    long long low = 0, high = 1000000000, mid, res = 0;
    while (low <= high)
    {
        mid = (high + low) / 2;
        if (check(mid))
        {
            res = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    cout << res;
}
int main()
{
    input();
    solve();
}