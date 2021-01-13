#include <bits/stdc++.h>
using namespace std;
int size_a, size_b;
float a[10000];
float b[10000];
float table[10000][10000];
int Max = 0;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> size_a >> size_b;
    for (int i = 0; i < size_a; i++)
        cin >> a[i];
    for (int i = 0; i < size_b; i++)
        cin >> b[i];
    for (int i = 0; i <= size_a; i++)
    {
        for (int j = 0; j <= size_b; j++)
        {
            if (i == 0 || j == 0)
                table[i][j] = 0;
            else if (a[i - 1] == b[j - 1])
                table[i][j] = table[i - 1][j - 1] + 1;
            else
                table[i][j] = max(table[i - 1][j], table[i][j - 1]);
        }
    }
    cout << table[size_a][size_b];
    return 0;
}