#include <iostream>
using namespace std;
int binarySearch(int arr[],int num,int left, int right)
{
    int mid = (right+left)/2;
    if (arr[mid] > num)   return binarySearch(arr,num,left,mid-1);
    if (arr[mid] < num)   return binarySearch(arr,num,mid+1,right);
    if (arr[mid] == num)  return mid;
}
int main()
{
    int array[]={1,2,3,4,5,6,7};
    cout << binarySearch(array,2,0,6);
}