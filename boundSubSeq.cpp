#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int lbound,ubound,n;
    cin >> n >> lbound >> ubound;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int t = 0;
    for(int i = 0; i < n; i++){
        int temp = 0;
        for(int j = i; j < n; j++){
            temp += arr[j];
            if (temp >= lbound && temp <= ubound){
                t += 1;
                continue;
            }
        }
    }
    cout << t;
}