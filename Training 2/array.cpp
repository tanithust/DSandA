#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main(){
    int arr[100],n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int mark[2], ans2[100];
    cout << "1 ";
    int k;
    for(int i = 0; i < n; i++){
        if (arr[i] < 0){
            cout << arr[i] << endl;
            k = i;
            break;
        }
    }
    int u = 0;
    for(int i = 0; i < n ; i++){
        if(arr[i] > 0){
            ans2[u] = arr[i];
            u++;
        }
    }
    if(u == 0){
        cout << "2" <<" ";
        for(int i = k + 1; i < n ; i++ ){
            if(arr[i] < 0){
                mark[u] = i;
                cout << arr[i] <<" ";
                u++;
            }
            if(u == 2) break;
        }
    }
    else{
        cout<< u << " ";
        for(int i = 0; i < u; i++) cout << ans2[i] << " ";
    }
    cout << endl << n - 1 - u << " ";
    int j = 0;
    for(int i = n-1; i >=0 ; i--){
        if(j < n-1-u && i != k && arr[i] <= 0 &&i != mark[0] && i != mark[1]){
            cout << arr[i] <<" ";
            j++;
        }
    }
}