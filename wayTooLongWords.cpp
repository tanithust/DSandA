#include<bits/stdc++.h>
#include <vector>
using namespace std;
vector<string> op;
int main(){
    string inp;
    int n,a;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> inp;
        if(inp.size() <= 10) op.push_back(inp);
        else{
            a = inp.size() - 2 ;
            stringstream ss; 
            ss << a;
            string temp = ss.str();
            op.push_back(inp.at(0) + temp + inp.at(a+1));
        }
    }
    for(int i = 0; i < n; i++ ) cout << op[i] << endl;
}