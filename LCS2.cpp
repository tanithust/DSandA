#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int arr1[1000],arr2[1000],l1,l2;
    cin >> l1 >> l2;
    for(int i = 1; i <= l1; i++){
        cin >> arr1[i];
    }
    for(int i = 1; i <= l2; i++){
        cin >> arr2[i];
    }
    int* lcs = new int[1000*1000];
    for(int i = 0; i <= l1; i++){
        for(int j = 0; j <= l2; j++){
            if (i == 0 || j == 0) {
                *(lcs + l2*i + j) = 0; 
                continue;
            }
            if (arr1[i] != arr2[j]) *(lcs + l2*i + j) = max( *(lcs + l2*(i-1)+j),*(lcs + l2*i + j-1) );
            else *(lcs+i*l2+j) = *(lcs+(i-1)*l2+j-1) + 1;
        }
    }
    cout << *(lcs+l1*l2+l2);
    return 0;
}