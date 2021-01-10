#include <iostream>
#include <bits/stdcp++.h>
using namespace std;

int main(){
    class tree{
       public:
        int data; 
        tree *left = NULL;
        tree *right = NULL;
    };
    void createLNode(tree *n){
        tree *new_node = new tree();
        cin >> new_node->data;
        n->left =  new_node;
    }
}