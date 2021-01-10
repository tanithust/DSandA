#include <bits/stdc++.h>
#include <vector>
using namespace std;
long long getMaxArea(long long hist[], long long n) 
{ 
    stack<long long> s; 
    long long max_area = 0; 
    long long tp;   
    long long area_with_top; 
    long long i = 0; 
    while (i < n) 
    { 
        if (s.empty() || hist[s.top()] <= hist[i]) 
            s.push(i++); 
        else
        { 
            tp = s.top();  
            s.pop();  
            area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);  
            max_area = max(max_area,area_with_top); 
        } 
    } 
    while (!s.empty()) 
    { 
        tp = s.top(); 
        s.pop(); 
        area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1); 
        max_area = max(max_area,area_with_top); 
    }   
    return max_area; 
} 
long long n;
long long arr[1000000];
vector<long long> out;
int main(){
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(true){
        cin >> n;
        if(n == 0) break;
        for(long long i = 0; i < n; i++){
            cin >> arr[i];
        }
        out.push_back(getMaxArea(arr,n));
    }
    for(long long i : out) cout << i << endl;
}