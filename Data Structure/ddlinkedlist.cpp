#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class node{
    public : 
    int data;
    node *next_node,*last_node;
};
node *current_node;
void createNode(node *n){
    node *new_node = new node();
    n->next_node = new_node;
    new_node->last_node = &n;
    cin >> new_node->data;
    new_node->next_node = NULL;
    current_node = new_node;
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
    current_node = &head;
    createNode(current_node);
    createNode(current_node);
    createNode(current_node);
    createNode(current_node);
    printList(&head);
}