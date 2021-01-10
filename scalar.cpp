#include <bits/stdc++.h>
#include <iostream>
using namespace std;

long long scalar(long long n,long long x[],long long y[]){
    sort(x,x+n);
    sort(y,y+n);
    long long product = 0 ;
    for(long long i = 0; i < n; i++){
        product += x[i]*y[n-1-i];
    }
    return product;
}
int main(){
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long t,n, x[1001],y[1001];
    cin >> t;
    long long res[t];
    for(long long i = 1; i <= t; i++){
        cin >> n;
        for(long long j = 0; j < n; j++){
            cin >> x[j];
        }
        for(long long j = 0; j < n; j++){
            cin >> y[j];
        }
        res[i] = scalar(n,x,y);
    }
    for(long long i = 1; i <= t; i++){
        cout << "Case #" << i <<": " << res[i] << endl;
    }
}