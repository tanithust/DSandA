#include <iostream>
using namespace std;
int fibSeq(int n)
{
    int result;
    if(n==0||n==1) result=1;
    else result=fibSeq(n-1)+fibSeq(n-2);
    return result;
}
int main()
{
    int n;
    cout<<"Enter your number: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<fibSeq(i)<<" ";
    }
}