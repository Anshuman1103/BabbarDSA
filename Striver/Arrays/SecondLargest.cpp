#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int secondLargest(const vector<int>& nums) {
    int largest = nums[0];
    int second = nums[0];
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] > largest){
            second = largest;
            largest = nums[i];
        }
        else if (nums[i] > second && nums[i] != largest){
            second = nums[i];
        }
    }
    return second;
}

int main() {
    vector<int> arr = {10, 5, 20, 8, 20, 15};
    int result = secondLargest(arr);
    if (result != -1)
        cout << "Second largest element: " << result << endl;
    else
        cout << "No second largest element found." << endl;
    return 0;
}