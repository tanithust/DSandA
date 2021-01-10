#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int *ptr, *arr;
    arr = new int[10];
    for(ptr = arr; ptr < arr +10 ; ptr++){
        cin >> *ptr;
    }
    for(ptr = arr; ptr < arr +10 ; ptr++){
        cout << *ptr <<" ";
    }
}