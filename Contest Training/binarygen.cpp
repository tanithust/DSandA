#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string binGen(int n,string s){
    int i;
    for(i = n - 1; i >= 0; i--){
        if(s.at(i) == '0'){
            s.at(i) = '1';
            break;
        }
        else s.at(i) = '0';
    }
    if (i < 0) return "-1";
    return s;
}
int main(){
    int n;
    string s;
    cin >> n;
    cin >> s;
    cout << binGen(n,s);
}