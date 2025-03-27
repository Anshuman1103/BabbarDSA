#include<bits/stdc++.h>
#include<iterator>
using namespace std;


int main(){
	int arr[] = {0};
	int largest = INT_MIN;
	int smallest = INT_MAX;
	for(int val : arr){
		if(val > largest) largest = val;
		if(val < smallest) smallest = val;
	}
	cout <<"Largest: " << largest << endl;
	cout <<"Smallest: " << smallest << endl;
	cout <<"Difference: " << largest - smallest << endl;
	return 0;
}