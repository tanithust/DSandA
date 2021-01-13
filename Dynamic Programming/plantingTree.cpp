#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int days[100000],seeds;
int main(){
    cin >> seeds;
    for(int i = 0; i < seeds; i++){
        cin >> days[i]; 
    }
    sort(days,days+seeds);
    reverse(days,days+seeds);
    int remain[100000];
    // remain[i] represent the day you have to wait until the trees fully grown up
    remain[0] = 0;
    for(int i = 1; i <= seeds; i++){
        if (days[i-1] > remain[i-1] - 1) remain[i] = days[i-1];
        else remain[i] = remain[i-1] - 1;
    }
    cout << seeds + remain[seeds] + 1; 
}