#include <bits/stdc++.h>
using namespace std; 

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,b;
    cin >> n >> b;
    long long arr[n];
    for(int i = 0; i < n;i++){
        cin >> arr[i];
    }
    long long maxSuffix[n],maxPrefix[n];
    maxSuffix[0] = arr[0];
    maxPrefix[n-1] = arr[n-1];
    for(int i = 1; i < n; i++){
        maxSuffix[i] = max(maxSuffix[i-1],arr[i]);
        maxPrefix[n-i-1] = max(maxPrefix[n-i],arr[n-i-1]);
    }
    long long ans = -1;
    for(int i = 1; i < n-1; i++){
        if(maxSuffix[i-1] - arr[i] >= b && maxPrefix[i+1] - arr[i] >= b){
            ans = max(ans,maxSuffix[i-1] + maxPrefix[i+1] - 2*arr[i]);
        }
    }
    cout << ans;
}