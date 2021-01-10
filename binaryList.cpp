#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <string>
using namespace std;
int n,k,i,c=0;

int checkCon(int arr[], int size, int rep){
    int flag = 0;
    for(int j = 0; j < size; j++){
        if (arr[j] == 0) {
            flag++;
            if (flag == rep) return 0;
        }
        else flag = 0;
    }
    return 1;
}
void binList(int arr[], int num, int size){
    arr[size] = num;
    size ++;
    if(checkCon(arr, size , i) == 0)
        return ;
    if (size < n){
        binList(arr,0,size);
        binList(arr,1,size);
    }
    if(size == n){
        if(checkCon(arr,n,i) == 1) {
            c++;
            if (c == k) {
                for(int m = 0; m < n; m++){
                    cout << arr[m] <<" ";
                }
                return;
            }
        }
            else{
                binList(arr,num,0);
            }
        }
    }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int arr[50001];
    cin >> n >> k >> i;
    binList(arr,0,0);
    binList(arr,1,0);
    if (c < k) cout << "-1";

}