#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int arr[500001],m,n,k,cnt=1;
void nextCom(){ 
    if(cnt == k){
        for(int i = 0; i < m; i++) cout <<arr[i]<<" ";
        return;
    }
    if(cnt < k){
        cnt++;
        arr[m] = n + 1;
        int a;
        for(a = m - 1; a >= 0;a-- ){
            if(arr[a+1] - arr[a] > 1){
                arr[a]++;
                for(int j = a + 1; j < m; j++ ){
                    arr[j] = arr[j-1] +1;
                }
                break;
            }
        }
        if(a < 0) {
            cout <<"-1";
            return;
        }
    }
    nextCom();
    return;
}
int main(){
    cin >> n >> m >> k; 
    if(n < m) {
        cout <<"-1";
        return 1;    
    }
    for(int i = 0; i < m; i++){
        arr[i] = i+1;
    }
    nextCom();
}