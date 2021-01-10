#include <iostream>
using namespace std;
int findMax(int a,int b)
{
    if (a > b) return a;
    else return b;
}
int findMaxArr(int array[],int n)
{
    int max=array[0];
    for(int i=0;i<n;i++)
    {
        if (array[i]>max) max=array[i];
    }
    return max;
}
int main()
{
    int n;
    cin >> n;
    int arr[n],s[n];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    s[0]=arr[0];
    for(int i=1;i<n;i++)
    {
        s[i]=findMax(s[i-1]+arr[i],arr[i]);
    }
    cout<<findMaxArr(s,n);
    return 0;
}