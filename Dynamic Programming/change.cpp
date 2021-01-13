#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int deno[6] = {1, 5, 10, 50, 100, 500};
int res[100000], n;
int main()
{
    cin >> n;
    int change = 1000 - n;
    res[0] = 0;
    for (int i = 1; i <= change; i++)
    {
        int j = 0;
        res[i] = INFINITY;
        while (i - deno[j] >= 0)
        {
            if (res[i - deno[j]] + 1 < res[i])
                res[i] = res[i - deno[j]] + 1;
            j++;
        }
    }
    cout << res[change];
}