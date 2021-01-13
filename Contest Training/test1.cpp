#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long result[100];
long long C(long long lower,long long upper)
{
    if ((upper == 1 && lower == 1) || upper == lower || upper == 0) return 1;
    else return C(lower-1, upper) + C(lower-1,upper-1);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long test;
    long long a,b,c;
    cin >> test;
    for (long long i=0; i < test; i++) {
        cin >> a >> b >> c;
        result[i]= C(a,b) % c; 
    }
    for (long long i=0; i< test; i++) {
        cout << result[i] << endl;
    }
}