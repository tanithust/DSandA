#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n,i;
    cout<<"Enter your number: ";
    cin>>n;
    cout<<"2 ";
    for(i=3;i<n;i++)
    {
        for(int j=2;j<i;j++)
        {
            if (i%j == 0) break;
            if (j>sqrt(i)) {
                cout<<i<<" "; 
                break;
                }
        }
    }
}