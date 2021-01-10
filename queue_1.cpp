#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int n, arr[100000],f[100000];
int bin(int k){
    int left=k,right=n,mid;
    while (right-left>1)
    {
        mid=(left+right)/2;
        if (f[mid]>=arr[k])  right=mid-1; else left=mid;

    }
    if ((right>k) && f[right]>=arr[k]) right--;
    return right;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) ;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    f[n]=arr[n];

    for(int i=n-1;i>=1;i--)
        f[i]=min(f[i+1],arr[i]);

    for(int i = 1; i <= n; i++)
        cout<<bin(i)-i-1<<" ";
}
