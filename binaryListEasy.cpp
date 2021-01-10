#include <bits/stdc++.h>
using namespace std;
int arr[20];
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i =0; i < n;i ++) {
        arr[i]=0;
        cout << arr[i];
    }
    cout << endl;
    for(int i = 1; i <= pow(2,n) - 1; i++){
        for(int i = n-1; i >=0; i--){
            if(arr[i] == 0) {
                arr[i] = 1;
                break;
            }
            else arr[i] = 0;
        }
        for(int i =0; i < n;i ++) cout << arr[i];
        cout <<endl;
    }
}