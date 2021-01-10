#include <bits/stdc++.h>
using namespace std;
int x[100];
int n;
bool candinate(int r, int c){
    for(int i =1 ; i < c; i++){
        if(x[i] == r || abs(x[i] - r) == abs(i-c)) return false;
    }
    return true;
}
void printSolution(){
    for(int i = 1; i <=n; i++) cout <<x[i] << " ";
    cout << endl;
}
void bTrack(int c){
    for(int r = 1; r <= n; r++){
        if(candinate(r,c)) {
            x[c] = r;
            if(c==n) printSolution();
            else bTrack(c+1);
        }
    }
}
int main(){
    cin >> n;
    bTrack(1);
}