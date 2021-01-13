#include <bits/stdc++.h>
using namespace std;
int n,l[10000],r[10000];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1 ;i <= n; i++){
        cin >> l[i] >> r[i];
    }
    int j=1,head[1000],tail[1000];
    for(int i = 1 ;i <= n;i++){
        if(l[i] == 0){
            head[j] = i;
            j++;
        }
    }
    for(int i = 1; i < j; i++){
        int temp = head[i];
        while(r[temp] != 0) temp = r[temp];
        tail[i] = temp;
    }
    for(int i = 1; i < j-1;i++){
        r[head[i]] = head[i+1];
        l[head[i+1]] = tail[i];
    }
    for(int i = 1; i <= n;i++) cout <<l[i] << " " << r[i]<<endl;
}