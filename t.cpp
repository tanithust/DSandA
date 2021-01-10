#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,k,a[10005],x;
ll gt=1ll;
int main()
{
    scanf("%d%d",&n,&x);

    for(int i=1;i<=min(n,13);i++) gt=gt*(ll)i;
    if (gt<x)
    {
        cout<<"-1";
        return 0;
    }
    int d=0,cs,cs2,tg;
    for (int i=1;i<=n;i++)
        a[i]=i;
        while (true)
        {
            int i=0;
        d++;
        if (d==x) {
        for (i=1;i<n+1;i++)
            printf("%d ",a[i]);
            return 0;
        }
        i=n-1;
        while ((i>0)&&(a[i]>a[i+1]))  i--;
        if (i>0)
        {
            k=n;
            while (a[i]>a[k]) k--;
            tg=a[i];
            a[i]=a[k];
            a[k]=tg;
            cs=i+1;
            cs2=n;
            while (cs<cs2)
            {
                tg=a[cs];
                a[cs]=a[cs2];
                a[cs2]=tg;
                cs++;
                cs2--;
            }
        }
        if (i==0) return 0;
        }
}

