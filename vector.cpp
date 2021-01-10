#include <iostream>
#include <vector>
using namespace std;
int findMax(vector<int> vec){
    int size = vec.size();
    int max = vec.at(0);
    for(int i = 0; i < size; i++){
        if(vec.at(i) > max) max = vec.at(i);
    }
    return max;
}

int main(){
    vector<int> vec;
    int arr[]={1,3,4,6,5};
    for(int i=0; i<5; i++)
    {
        vec.push_back(arr[i]);
    }
    cout << vec.back();
}