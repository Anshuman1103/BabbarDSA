// C++ program to find minimum of coins
// to make a given change sum
#include<bits/stdc++.h>
using namespace std;

int minCoins(vector<int> coins, int sum){
    int count = 0;
    sort(coins.begin(), coins.end(), greater<>());

    int currSum = 0;

    for(int i = 0; i < coins.size(); i++){
        while(currSum + coins[i] <= sum){
            currSum += coins[i];
            count++;
        }
        if(currSum == sum){
            return count;
        }
    }
    return -1;
}

int main() {
    vector<int> coins =  {5, 1};
    int sum = 0;
    cout << minCoins(coins, sum);
    return 0;
}
