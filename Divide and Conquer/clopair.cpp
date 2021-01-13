#include <bits/stdc++.h>
using namespace std;

class point {
    public:
    int x,y;
}
int compairX(const void *a,const void *b){
    point *p1 = (point *)a,*p2 = (point *)b;
    return (p1->x - p2->x); 
}
int compairY(const void *a,const void *b){
    point *p1 = (point *)a,*p2 = (point *)b;
    return (p1->y - p2->y);
}
float distance(point p1, point p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}
float bruteForce(point p[],int n){
    float min = FLT_MAX;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j<n;j++){
            min = min(min,distance(p[i],p[j]));
        }
    }
    return min;
}
float min(float x, float y){
    return (x < y) ? x : y ;
}
float stripClosest(point strip[],int size, float d){
    float min = d;
    qsort(strip, size, sizeof(point),compairY);
    for(int i = 0; i< size;i++){
        for(int j = i +1;)
    }
}
int main(){
    
}