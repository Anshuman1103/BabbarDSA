#include <bits/stdc++.h>

using namespace std;

void remove(vector<int>& nums) {
    int i = 0;
    for(int j = 1; j < nums.size(); j++){
        if(nums[i] != nums[j]){
            i++;
            nums[i] = nums[j];
        }
    }
    int newSize = i+1;
}

int main() {
    vector<int> arr = {1, 1, 2, 2, 3};
    remove(arr);
    for(auto i : arr){
        cout << i << " ";
    }
    return 0;
}