#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int a,b;
    long long c= pow(10,9) + 7;
    cin >> a>> b;
    long long mod = a % c,result=mod;
    for(int i=2; i<=b ;i++)
    {
        result = (result * mod) % c; 
    }
    cout << result;
} 