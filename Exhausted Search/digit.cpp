#include <bits/stdc++.h>
using namespace std;

int n;
int a[7];
int visited[10];
int ans = 0;
bool check(){
    return (n == (a[0]*100 + a[1]*10 + a[2] - a[3]*100 - 62 + a[4]*1000 +a[5]*100+a[6]*10+a[2]));
}

void digit(int k){
    if(k > 6){
        if(check()) ans++;
        return;
    }
    for(int i =1; i<10;i++){
        if(!visited[i]){
            a[k] = i;
            visited[i] = true;
            digit(k+1);
            visited[i] = false;
        }
    }

}
int main() {
    cin >> n;
    digit(0);
    cout << ans;
}