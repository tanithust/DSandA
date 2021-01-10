#include <iostream>
using namespace std;
void move(int n, int strt, int med, int dest)
{
    if( n==1) cout << strt << "->" << dest << endl;
    else
    {
        move(n-1,strt,dest,med);
        move(1,strt,med,dest);
        move(n-1,med,strt,dest);
    }
}
int main(){
    int n ;
    cin >> n;
    move(n,1,2,3);
}