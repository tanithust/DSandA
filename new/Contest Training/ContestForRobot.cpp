#include <bits/stdc++.h>
using namespace std;
int solvedProblem(int a[], int n)
{
    int solved = 0;
    for (int i=0 ; i<n ; i++)
    {   
        if (a[i]==1) solved++;    
    }
    return solved;
}
int findCommonProblem(int a[], int b[], int n)
{
    int common=0;
    for(int i=0; i<n; i++)
    {
        if(a[i]==b[i] && a[i]==1) common++;
    }
    return common;
}
int compare(int a[], int b[], int n)
{
    int comp = 1;
    for (int i=0; i<n ; i++)
    {
        if (a[i] != b[i]) {
            comp = 0;
            break;
        }
    }
    return comp;
}
int main()
{
    int n;
    cin >> n;
    int RoboCoder[n],BionicSolver[n];
    for(int i=0; i<n ; i++)
    {
        cin >> RoboCoder[i];
    }
    for(int i=0; i<n ; i++)
    {
        cin >> BionicSolver[i];
    }
    int roboSolved=solvedProblem(RoboCoder,n);
    int bionicSolved=solvedProblem(BionicSolver,n);
    int commonSolved=findCommonProblem(RoboCoder,BionicSolver,n);
    int compareResult=compare(RoboCoder,BionicSolver,n);
    if (compareResult == 1 || commonSolved == roboSolved) cout << "-1";
    else {
        int max = (bionicSolved - commonSolved)/(roboSolved - commonSolved) +1 ;
        cout << max; 
        }  
}