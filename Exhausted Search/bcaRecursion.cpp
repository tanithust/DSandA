#include <bits/stdc++.h>
using namespace std;
int m,n,k,c1,c2;
int t[31][31],conflict[100][100];
int teacher[31]; // teacher[i] is the number of course that teacher i could teach
int course[31];
int totalLoad[31]; 
bool check(int v,int k){
    if(course[v] == 1) return false;
    for(int i = 0; i < )
}
int bca(int k){
    for(int i = 0; i < teacher[k]; i++){
        int a = t[k][i];
        if(course[a] == 0 && ){
            course[a] = 1;
            totalLoad[k]++;
        }
    }
}
int main(){
    cin >> m >>n;
    for(int i = 0; i < m; i++){
        cin >> teacher[i];
        for(int j = 0; j < teacher[i]; j++) cin >> t[i][j];
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
}