#include <iostream>
using namespace std;
int size = 1000;
int top = -1;
int stack[1000];
bool isEmpty()
{
    return top == -1 ? true : false ;
}
bool isFull()
{
    return top == size ? true : false;
}
void push(int item)
{
    if(isFull()) {
        cout <<"Your stack is full, can't push any more item"<<endl;
        return;
    }
    else
    {
    top++;
    stack[top] = item;
    }
}
void pop()
{
    if(isEmpty()) {
        cout <<"Your stack is empty, can't pop any item"<<endl;
        return; 
    }
    else 
    {
        top--;
        stack[top] = 0;
    }

}
int peek()
{
    return stack[top];
}
int main(){
    int num,x;
    cin >> num;
    for(int i=0; i<num; i++)
    {
        cin >> x;
        push(x);
    }
    for(int i=0; i<num; i++)
    {
        cout<<stack[i]<<" ";
    }
}