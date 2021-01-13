#include <bits/stdc++.h>
using namespace std;
typedef struct s{
    string string;
}strng;
int numOfZero(string str)
{
    int numberOfZero=0,numberOfOne=0,i,leftZero=0,rightZero=0;
    for(i=0;i<str.length();i++)
    {
        if(str[i]=='0') numberOfZero++;
    }
    for(i=0;i<str.length();i++)
    {
        if(str[i]=='1') numberOfOne++;
    }
    if (numberOfOne < 2) return 0;
    for(i = 0;str[i] != '1';i++)
        leftZero++;
    for(i=str.length()-1;str[i] != '1';i--)
        rightZero++;
    return numberOfZero- rightZero - leftZero;
}
int main()
{   
    int n,i;
    cin>>n;
    strng a[n];
    for(i=0;i<n;i++){
        cin>>a[i].string;
    }
    for(i=0;i<n;i++){
        cout<<numOfZero(a[i].string)<<endl;
    }
}