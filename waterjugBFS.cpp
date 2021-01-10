#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int pour(int from, int to, int target){
    int j1 = from;
    int j2 = 0;
    int step = 1;
    while(from != target && to != target){
        int temp = min(to - j2, j1);
        j2 += temp;
        j1 -= temp;
        step++;
        if (j1 == target || j2 == target) break;
        if (j1 == 0) {
            j1 = from;
            step++;
        }
        if (j2 == to) {
            j2 = 0;
            step++;
        }
    }
    return step;
}
int gdc(int a,int b){
    if(a == 0) return b;
    else return gdc(b%a,a);
}
int minStep(int cap1, int cap2, int target){
    if (target > max(cap1,cap2) || target % gdc(cap1,cap2) != 0 )
    return -1;
    else
    return min(pour(cap1,cap2,target),pour(cap2,cap1,target));
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int res[1000];
    int a,b,c;
    cin >> a >> b >> c;
    cout << minStep(a,b,c) ;
}