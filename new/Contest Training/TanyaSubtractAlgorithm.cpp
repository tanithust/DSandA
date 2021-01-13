#include <bits/stdc++.h>
using namespace std;
int main(){
    int num, times;
    cin >> num >> times;
    for (int i=1;i <= times;i++)
    {
        if (num % 10 != 0) num -=1;
        else num /=10;
    }
    cout<< num;
}