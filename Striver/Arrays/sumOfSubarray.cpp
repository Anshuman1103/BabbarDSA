#include<bits/stdc++.h>

using namespace std;

int largestSum(vector<int> arr){
    int maxSum = INT_MIN;
    for(int i = 0; i < arr.size(); i++){
        int sum = 0;
        for(int j = i; j < arr.size(); j++){
            sum += arr[j];
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
}

int kadane(vector<int> arr){
    int maxSum = INT_MIN;
    int sum = 0;
    for(int i = 0; i < arr.size(); i++){
        sum += arr[i];
       if(sum > maxSum){
        maxSum = sum;
       }

        if(sum < 0){
            sum = 0;
        }
    }
    return maxSum;
}


int main() {
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int ans = kadane(arr);
    cout << ans << endl;
}