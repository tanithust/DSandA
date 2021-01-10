#include <iostream>
using namespace std;
int main(){
    int *ptr,*arr,*sort,temp;
    arr = new int[5];
    //Input
    for(ptr = arr ; ptr < arr+5 ; ptr++)
    {
        cin >> *ptr;
    }
    //Sort
    for(ptr = arr ; ptr < arr+5 ; ptr++)
    {
        for(sort = ptr + 1 ; sort < arr +5 ; sort ++)
            if (*sort < *ptr )
            {
                temp=*ptr;
                *ptr=*sort;
                *sort=temp;
            }
    }
    //Print
    for(ptr = arr ; ptr < arr+5 ; ptr++)
    {
        cout << *ptr << " ";
    }
}