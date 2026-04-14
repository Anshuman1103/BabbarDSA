#include <bits/stdc++.h>
using namespace std;

pair<int,int> twoSum(vector<int> nums, int target){
    unordered_map<int,int> mpp;
    for(int i = 0; i < nums.size(); i++){
        mpp[nums[i]] = i;
        int diff = target - nums[i];
        if(mpp.find(diff) != mpp.end()){
            return {mpp.find(diff)->second,i};
        }
    }
    return {-1,-1};
}

void productOfArray(vector<int> nums){
    
}

int noOfSubArrayWithSum(vector<int> &nums, int target){
    unordered_map<int,int> mpp;
    int count = 0, sum = 0;
    mpp[0] = 1;
    for(int i = 0; i < nums.size(); i++){
        sum += nums[i];
        int diff = sum - target;
        if(mpp.count(diff)){
            count += mpp[diff];
        }
        mpp[sum]++;
    }
    return count;
}

int main() {
    vector<int> nums = {2,5,4,7};
    int target = 9;
    pair<int,int> ans = twoSum(nums, target);
    cout << ans.first << " " << ans.second << endl;

    vector<int> nums2 = {1,2,3,4,5};
    int target2 = 9;
    int ans2 = noOfSubArrayWithSum(nums2, target2);
    cout << ans2 << endl;

    return 0;
}