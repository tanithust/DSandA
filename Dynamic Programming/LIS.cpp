#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int input[500000],lis[500000],s;
int main(){
    cin >> s;
    for(int i = 0; i < s; i++){
        cin >> input[i];
        lis[i] = 1;
    }
    for(int i = 1; i < s; i++){
        for(int j = 0; j < i; j++){
            if(lis[i] < lis[j] + 1 && input[i] > input[j]) lis[i] = lis[j] + 1;
        }
    }
    int max = 1;
    for(int i = 0; i < s; i++ ){
        if(max < lis[i]) max = lis[i];
    } 
    cout << max;
}