#include <bits/stdc++.h>
using namespace std;
double findmax(double arr[],int s,int l){ 
    double d = -1;
    for(int i = 0; i < s -1; i++){
        d = max(arr[i+1] - arr[i],d);
    }
    return d;
}
int main(){
    int n;
    double l,arr[1001];
    cin >> n >> l;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    //cout<<setprecision(9) << fixed << findmax(arr,n,l);
    double d,s=arr[0],e = l - arr[n-1];
    d = max(s,e);
    double temp = findmax(arr,n,l) / 2;
    d =max(d,temp);
    cout << setprecision(9) << fixed << d;
}