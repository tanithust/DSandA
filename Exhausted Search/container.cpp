#include <bits/stdc++.h>
using namespace std;

int main(){
    int h,w,n;
    cin >> h >> w >> n;
    int height,width;
    int area = 0 ;
    for(int i = 0; i < n; i++){
        cin >> height >> width;
        area += height * width;
    }
    if(area > h*w) cout <<"0";
    else cout << "1";
}