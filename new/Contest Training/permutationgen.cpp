#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int partition(int arr[],int high, int low){
    int left = low;
    int right = high - 1;
    int piv = arr[high];
    while(true){
        while(left <= right && arr[left] < piv) left++;
        while(left <= right && arr[right] > piv) right--;
        if(right <= left) break;
        swap(arr[left],arr[right]);
        right--;
        left++;
    }
    swap(arr[left],arr[high]);
    return left;
}

void quicksort(int arr[], int high, int low){
    if(high > low ){
        int pi = partition(arr, high, low);
        quicksort(arr, high, pi + 1);
        quicksort(arr, pi - 1, low);
    }
}
//find the smallest number that is bigger than n
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
            quicksort(arr,size-1,size+1-i);
            break;
        }
    }
    if(i > size) cout << "-1";
     else{
         for(int i = 0; i < size; i++ ){
             cout << arr[i] <<" ";
         }
    }
}