#include <iostream>
#include <stack>
using namespace std;
int main(){
    stack<int> myStack;
    for(int i = 0; i < 10; i++){
        myStack.push(i*10);
    }
    cout << myStack.top();
}