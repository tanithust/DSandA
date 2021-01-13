#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int arr[50000];
    int size, lim;
    cin >> lim >> size;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    arr[size] = lim + 1;
    for (int i = size - 1; i >= 0; i--)
        if (arr[i + 1] - arr[i] > 1)
        {
            for (int j = 0; j < i; j++)
                cout << arr[j] << " ";
            arr[i]++;
            cout << arr[i] << " ";
            for (int j = i + 1; j < size; j++)
            {
                arr[j] = arr[j - 1] + 1;
                cout << arr[j] << " ";
            }
            return 0;
        }
    cout << "-1";
}
