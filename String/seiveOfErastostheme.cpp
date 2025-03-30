#include<bits/stdc++.h>
using namespace std;

int main(){
	int n ;
	cin >> n;
	vector<int> v(n+1,1);

	for (int i = 2; i <= n; i++){
		if(v[i] == 1){
			for(int j = i*i; j <= n; j += i){
				v[j] = 0;
			}
		}
	}

	for(int i = 2; i <= n; i++){
		cout << i <<" " << v[i] << endl;
	}
	
	return 0;
}