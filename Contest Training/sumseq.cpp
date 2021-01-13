#include <iostream>
#include <math.h>
using namespace std;
int main(){
    long long sum=0,n,x=pow(10,9)+7;
    cin>> n;
    long long arr[n];
    for(int i=0 ; i<n ; i++ )
    {
        cin >> arr[i];
    }
    for(int i=0 ; i<n ; i++)
    {
        sum += arr[i];
    }
    cout << sum % x;

}