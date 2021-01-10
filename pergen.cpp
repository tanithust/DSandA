#include <bits/stdc++.h>
using namespace std;

int main (){
	int n,i,order,value;
	cin >> n;
	int a[n];
	for (i=0; i<n; i++){
		cin >> a[i] ;
	}
	bool valid = false;
	for (i=n-1; i>=1; i--){
		if (a[i-1] < a[i]){
			order = i-1;
			value = a[i-1];
			valid = true;
			break;
		}
	}
	if (valid == false){
		cout << -1;
	} else{
		for (i=n-1; i>=0; i--){
			if (a[i] > value){
				a[order] = a[i];
				a[i] = value;
				break;
			}
		}
		for (i=0; i<n; i++){
			cout << a[i] << " ";
		}
	}
	return 0;
}