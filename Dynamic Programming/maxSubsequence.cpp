#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int arr[1000000], res[1000000];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    res[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        res[i] = max(arr[i], res[i - 1] + arr[i]);
    }
    int m = 0;
    for (int i = 0; i < n; i++)
        m = max(m, res[i]);
    cout << m;
}