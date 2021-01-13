#include <bits/stdc++.h>
using namespace std;
int main(){
    unsigned long long num1,num2,first1,first2,last1,last2,first,last;
    cin >> num1 >> num2;
    if (num1+num2 <10)
    cout<< num1 + num2;
    else{
    first1 = num1/10;
    first2 = num2/10;
    last1 = num1 % 10;
    last2 = num2 % 10;
    if ( (last1 + last2) > 9 )
    {
        last = (last1 + last2 ) % 10;
        first = first1 + first2 + 1;
    }
    else 
    {
        last = last1 + last2;
        first = first1 + first2;
    }
    cout<<first<<last;
    }

}