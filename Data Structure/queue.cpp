#include <iostream>
using namespace std;
#define size 1000 
int rear = -1;
int front = 0;
int queue[1000];
bool isEmpty(){
    return (front < 0 || front > rear) ? true : false ;
}
bool isFull(){
    return rear == size -1 ? true : false;
}
void enqueue(int item){
    if (isFull()) {
        cout <<"Your queue is full"<<endl;
        return;
        }
    rear++; 
    queue[rear]=item;
}
void dequeue()
{
    if(isEmpty()) {
        cout<< "Your queue is empty"<<endl;
        return;
        }
    else 
    queue[front] =0;
    front ++;
}
int peek()
{
    return queue[front];
}
int main(){
    int n,x;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x;
        enqueue(x);
    }
    for(int i=0; i<n; i++){
        cout<<queue[i]<<" "<<endl;
    }
}