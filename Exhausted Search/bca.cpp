#include <bits/stdc++.h>
using namespace std;
int m,n,k,c1,c2;
int t[31][31],conflict[100][100];
vector<int> x[31]; // x[i] is array of teacher that assigned for subject i
int totalLoad[31];
int teacher[31]; // teacher[i] is the number of subject that teacher i could teach
int course[31]; // course[i] is the teacher that assigned for course i
int maxLoad = INT_MAX;

int check(int v, int k){
    for(int i = 1; i < k; i++){
        if(conflict[i][k] && v == course[i]) return 0;
    }
    return 1;
}
void bca(int k){
    for(int u = 0; u < x[k].size(); u++){
        int v = x[k][u];
        if(check(v,k)){
            course[k] = v;
            totalLoad[v]++;
            if(totalLoad[v] < maxLoad){
                if(k == n){
                int mx = 0;
                for(int i = 0; i < m; i++){
                    mx = max(mx,totalLoad[i]); 
                }
                maxLoad = min(maxLoad,mx);
                }
                else{
                    bca(k+1);
                }
            }
            totalLoad[v]--;
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m >>n;
    for(int i = 0; i < m; i++){
        cin >> teacher[i];
        for(int j = 0; j < teacher[i]; j++) {
            cin >> t[i][j];
            x[t[i][j]].push_back(i);
        }
    }
    cin >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) conflict[i][j] = 0;
    }
    for(int i = 0; i < k;i++){
        cin >> c1 >> c2;
        conflict[c1][c2] = 1; 
        conflict[c2][c1] = 1;
    }   
    bca(1);
    if(maxLoad == INT_MAX ){
        cout << -1; 
        return 1;
    }
    cout << maxLoad;
}