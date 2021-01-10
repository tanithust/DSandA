#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int state[n-1];
    for(int i = 0; i < n-1; i++){
        if (arr[i] < arr[i+1]) state[i] = 1;
        if (arr[i] == arr[i+1]) state[i] = 0;
        if (arr[i] > arr[i+1]) state[i] = -1;
    }
    int l = 0, r = 0,curHill = 0,hill = 0;
    if (state[0] == 1) l = 1;
    for(int i = 1; i < n-1;i++){
        if (state[i] == 1 && state[i-1] != 1){
            curHill = min (l,r);
            hill = max(curHill,hill);
            l = 0;
            r = 0;
        }
        if (state[i] == 1) l++;
        if (state[i] == -1) r++;
        if (state[i] == 0){
            if(state[i-1] == -1){
                curHill = min (l,r);
                hill = max(curHill,hill);
                l = 0;
                r = 0;
            }
            else{r=0;l=0;}
        }
    }
    if(state[n-2] == -1) {
        curHill = min (l,r);
        hill = max(curHill,hill);
    }
    l = 0; r =0;
    int curVal = 0, val =0;
    if (state[0] == -1) l = 1;
    for(int i = 1; i < n; i++){
        if(state[i] == -1 && state[i-1] != -1){
            curVal = min(l,r);
            val = max(curVal,val);
            l = 0;
            r = 0;
        }
        if (state[i] == -1) l++;
        if (state[i] == 1) r++;
        if (state[i] == 0){
            if(state[i-1] == 1){
                curVal = min(l,r);
                val = max(curVal,val);
                l = 0;
                r = 0;
            }
            else{l=0;r=0;}
        }
    }
    if(state[n-2] == 1){
        curVal = min(l,r);
        val = max(val,curVal);
    }
    cout << hill <<" "<<val;
}