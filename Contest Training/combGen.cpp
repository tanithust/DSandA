#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int combGen(int arr[], int size, int lim){
    int ava[50000];
    int k = 0,i;
        for(i = 1; i <= lim; i++){
            if(arr[k] == i ){
                ava[i] = 0;
                k++;
            }
            else ava[i] = 1; 
        }
    int *ptr;
    ptr = arr;
    for(i = size - 1; i >= 0 ;i--){
        for(k = arr[i]; k <= lim; k++){
            if(arr[i] < k && ava[k] == 1){
                int p = 1, s = arr[i] ;
                for(int j = i; j < size; j++ ){
                    *(ptr+j) = s +p;
                    p++;  
                }
                return 1;
            }
        } 
    }
    if(i < 0) return -1;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) ;
    int arr[50000];
    int size, lim;
    cin >> lim >> size;
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }
    if(combGen(arr,size,lim) == 1){
        for(int i = 0; i < size; i++){
            cout << arr[i]<< " ";
        }
    }
    else cout<< "-1";
}