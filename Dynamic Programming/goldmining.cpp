#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,l1,l2;
    cin >> n >> l1 >> l2;
    int arr[n],res[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i]; 
        res[i] = 0;
    }
    res[0] = arr[0];
    for(int i = 1; i < n; i++ ){
        if(i<l1){
            res[i] = arr[i];
        }
        else{
            for(int j = l1; j <= l2 && i-j >=0; j++){
                if(res[i-j] + arr[i] > res[i]) res[i] = res[i-j] + arr[i];
            }
        }
    }
    int max=0;
    for(int i = 0; i < n; i++){
        if(res[i] > max) max= res[i];
    }
    cout << max;
}