#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    string input;
    vector<char> order;
    cin >>input;
    order.push_back(input.at(0));
    for(int i = 1; i < input.length(); i++){
        if(input[i] == '+'){
            if(order.back() == '+') order.pop_back();
            else order.push_back(input.at(i));
        }
        if(input[i] == '-'){
            if(order.back() == '-') order.pop_back();
            else order.push_back(input.at(i));
        }
    }
    if(order.size() == 0) cout << "yes";
    else cout << "no";
    return 0;
}