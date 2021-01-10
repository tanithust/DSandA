#include <bits/stdc++.h>
using namespace std;
int n,q,a,b,x;
long long road[100000];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0;i < n; i++) cin >> road[i];
    int roughness = 1;
    int temp;
    for(int i = 0;i < n-1; i++){
        temp = road[i];
        if(temp != road[i+1]) roughness++;
    }
    cin >> q;
    if(n == 1) while(q--) cout << 1 <<endl;
    else{
        while(q--){
            cin >> a >> b;
            if(road[a-1] == road[a+1]){
                if(road[a] == road[a-1]){
                    if(b == a) cout << roughness <<endl;
                    else{
                        roughness -= 2;
                        cout << roughness <<endl;
                    }
                }
                else{
                    if(b != road[a-1])
                }
            }
        }
    }
}