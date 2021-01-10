#include <bits/stdc++.h>
#define vc 1000000
using namespace std;
int weight[100],use[100],n,b;
int knapSack(int w[], int u[], int n, int we){
	if(we < 0) return INT_MIN;
	if(we == 0 || n < 0) return 0;
	int include = u[n]+knapSack(w,u,n-1,we-w[n]);
	int exclude = knapSack(w,u,n-1,we);
	return max(include,exclude);
}
int main(){
	cin >> n >> b;
	for(int i = 0; i <n; i++){
		cin >> weight[i] >> use[i];
	}
	cout << knapSack(weight,use,n-1,b);
}