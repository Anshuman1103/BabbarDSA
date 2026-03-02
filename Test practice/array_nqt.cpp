#include<bits/stdc++.h>
using namespace std;

void push0toEnd(vector<int> &nums){
    int low = 0, high = 0;
    int n = nums.size();
    while(high < n){
        if(nums[high] != 0){
            swap(nums[high], nums[low]);
            high++;
            low++;
        }
        else high++;
    }

    for(auto num: nums){
        cout << num << " ";
    }
    cout << endl;
}

void numberOfVehicle(int w, int v){
    int x = 0 , y = 0;
    y = (w - (2 * v))/2;
    x = v - y;

    if(floor(x) != x || floor(y) != y || x < 0 || y < 0){
        cout << "Invalid" << endl;
        return ;
    }

    cout << "TW :" << x << " , "<< "FW : "<< y << " " << endl;
}

int oddOneOut(vector<int> &nums){
    int count = 0;
    int currElement = nums[0];
    for(auto num : nums){
        if(num == currElement){
            count++;
        }
        else{
            if(count % 2 != 0){
                return currElement;
            }
            currElement = num;
            count = 1;
        }
    }
    return -1;
}

void replaceRank(){

}

void conveyorBelt(vector<int>&nums, int target){
    int low = 0;
    int high = 0;
    while(low <= high){
        
    }
}

int main(){
    vector<int> nums = {0, 1, 0, 3, 12};
    push0toEnd(nums);
    numberOfVehicle(10, 5);
    numberOfVehicle(14, 4);
    numberOfVehicle(15, 3);
    vector<int> nums2 = {2, 2, 1,1, 3, 3, 4, 4};
    cout << oddOneOut(nums2) << endl;
}