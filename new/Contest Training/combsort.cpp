#include <iostream>
#include <math.h>
#include <string.h>
#include<bits/stdc++.h>
using namespace std;
void swap(float *a,float *b)
{
    float temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
long long partition(float arr[],long long low,long long high)
{
    float piv = arr[high];
    long long right = high - 1;
    long long left = low;
    while(true)
    {
        while(left <= right && arr[left] < piv ) left++;
        while(right >= right && arr[right] > piv ) right--;
        if(right <= left) break;
        swap(&arr[left],&arr[right]);
        right--;
        left++;
    }
    swap(&arr[high],&arr[left]);
    return left;
}
void combSort(float arr[], long long low, long long high)
{
    if (low < high)
    {
        int pi = partition( arr, low, high);
        combSort(arr, low, pi - 1);
        combSort(arr, pi + 1, high);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) ;
    long long n;
    cin >> n;
    float arr[n];
    for(long long i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    combSort(arr,0,n-1);
    for(long long i=0; i < n; i++)
    {
        cout << fixed << setprecision(2) <<arr[i] << " ";
    }
}