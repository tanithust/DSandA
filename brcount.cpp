#include <bits/stdc++.h>
#define N 2000
#define mod 1e9+7
using namespace std;
string s;
int n;
long long f[N][N];
main()
{
    cin>>s;
    n=s.length();
    
    if (s[0]==')')
    {
        cout<<0;
        return 0;
    }
    
    f[0][1]=1;
    for(int i=1;i<n;i++)
        for(int j=0;j<n;j++)
        {
            if (s[i] == '(' || s[i] == '?') 
            {
                if ( j > 0) f[i][j]=f[i][j]+f[i-1][j-1]%mod;
            }
            if (s[i] == ')' || s[i] == '?')
            {
                f[i][j]=f[i][j] + (f[i-1][j+1]%mod);
            }
        }
    cout<<f[n-1][0]%mod;
}
