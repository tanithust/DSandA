#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n,s;
    cout<<"Enter your number: ";
    cin>>n;
    cout<<"1 ";
    for(int i=3;i<n;i++)
    {
        s=0;
        for(int j=1;j<=i/2;j++)
        {
            if(i%j == 0) s += j;
        }
        if(s==i) cout<<s<<" ";
    }
}