#include <bits/stdc++.h>
using namespace std;
int mat[3][3] = {{2, -1, -1},
                 {-1, 3, -1},
                 {-1, -1, 3}};
int mu(int x){
    if(x%2 == 0) return 1;
    else return -1;
}
int cal(int x,int y)){
    if(y-x == 1) return mat[x][x]*mat[y][y]-mat[x][y]*mat[y][x];
    else {
        int det = 0;
        for(int i = x; i <=y;i++){
            det += mu(mat[0][i])*cal(x+1,y);
        }
    }
}
int main()
{
    
}