#include <iostream>
using namespace std;
class node{
    public: 
    int data;
    node *nextnode = NULL;    
};
node *current;
void createNode(node *n){
    node *new_node = new node();
    n->nextnode = new_node;
    cin >> new_node->data;
    new_node->nextnode = NULL;
    current = new_node;
    return;
}
void printList(node *n){
    while(n != NULL){
        cout << n->data << " " ;
        n = n->nextnode;
    }
    return;
}
int main(){
    node head;
    cin >> head.data;
    current = &head;
    createNode(current);
    createNode(current);
    createNode(current);
    createNode(current);
    printList(&head);
}