#include <bits/stdc++.h>
using namespace std;

int findMin(int arr[],int n, int start, int end){
    int i,min,index;
    for(i = start; i <= end; i++ ){
        if (arr[i] > n) {
            min = arr[i];
            index = i;
            for(int k = i; k <= end; k++ ){
                if(arr[k] > n && arr[k] < min){
                    min = arr[k];
                    index = k;
                }
            }
            break;
        }
    }
    if(i == end + 1) return -1;
    return index;
}

int main(){
    int arr[10000];
    int i, size;
    cin >> size;
    for(i = 0; i <= size -1; i++){
        cin >> arr[i];
    }
    for(i = 2; i <= size; i++){
        if(findMin(arr,arr[size-i],size+1-i,size-1) != -1){
            int temp = findMin(arr,arr[size-i],size+1-i,size-1);
            swap(arr[size-i],arr[temp]);
            sort(arr+size-1,arr+size-i);
            break;
        }
    }
    
}