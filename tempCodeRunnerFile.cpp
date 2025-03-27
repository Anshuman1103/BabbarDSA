#include<bits/stdc++.h>
using namespace std;

bool isPerfect(int n){
    int sum = 0;
	for(int i = 1; i <= (n/2); i++){
		if(n % i  == 0){
            sum += i;
        }
	}
	if(sum == n) return 1;
	else return 0;
}

int main(){
	int n;
	cout <<"Enter the number"<< endl;
	cin >> n;
	if(isPerfect(n)){
		cout <<"Perfect" << endl;
	}
	else{
		cout<<"Not Perfect"<< endl;
	}
	return 0;
}