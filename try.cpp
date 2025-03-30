#include<bits/stdc++.h>
using namespace std;

int main(){
	int  n;
	cout <<"Enter the number: "<< endl;
	cin >> n;
	int a = 0, b = 1;
	int next;
	for(int i = 0; i < n; i++){
		cout << a << " " ;
		a = b;
		b = a+b;
	}
	return 0;
}