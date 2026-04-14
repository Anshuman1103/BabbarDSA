#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>
#include<map>
using namespace std;

int missingNumber(vector<int>& nums, int n){
    int sum = (n * (n+1))/2;
    int arrSum = 0;
    for(auto i : nums){
        arrSum += i;
    }
    return sum - arrSum;
}

int secondLargest(vector<int>& nums){
    int largest = nums[0];
    int secLargest = nums[0];
    for(auto num: nums){
        if(num > largest){
            secLargest = largest;
            largest = num;
        }
        else if(num > secLargest && num != largest){
            secLargest = num;
        }
    }
    return secLargest;
}

// Dutch National Flag Algorithm
void sort012(vector<int> nums){
    int low = 0, mid = 0, high = nums.size()-1;
    while(mid <= high){
        if(nums[mid] == 0){
            swap(nums[mid], nums[low]);
            low++;
            mid++;
        }
        else if(nums[mid] == 2){
            swap(nums[mid], nums[high]);
            high--;
        }
        else mid++;
    }

    for(auto num: nums){
        cout << num << " ";
    }
    cout << endl;
    return;
}

//Kadane's Algorithm
int maxSubarraySum(vector<int> nums){
    int currentSum = nums[0];
    int maxSum = nums[0];
    for(int i = 1; i < nums.size(); i++)
    {
        currentSum = max(nums[i], currentSum + nums[i]);
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
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

void rightRotate(vector<int>& nums, int k){
    int n = nums.size();
    if (n == 0) return;
    k = k % n;
    
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}

void leftRotate(vector<int>& nums, int k){
    int n = nums.size();
    if (n == 0) return;
    k = k % n;

    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
    reverse(nums.begin(), nums.end());
}

void subarraySumforPositive(vector<int> nums, int target){
    int n = nums.size();
    int start = 0;
    int sum = 0;
    for(int end = 0; end < n; end++){
        sum += nums[end];
        while(sum > target && start <= end){
            sum -= nums[start];
            start++;
        }
        if(sum == target){
            cout << "Subarray found between indices " << start << " and " << end << ": ";
            for(int i = start; i <= end; i++){
                cout << nums[i] << " ";
            }
            cout << endl;
        }
    }
    return;
}

void subarraySumforNegative(vector<int> nums, int target){
    unordered_map<int,int> mp;
    int prefix_sum = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        prefix_sum += nums[i];

        if(prefix_sum == target)
        {
            cout << "Subarray from 0 to " << i << endl;
        }

        if(mp.find(prefix_sum - target) != mp.end())
        {
            cout << "Subarray from "
                 << mp[prefix_sum - target] + 1
                 << " to "
                 << i << endl;
        }

        mp[prefix_sum] = i;
    }
}

void findPairWithGivenSum(vector<int> nums, int target){
    int n = nums.size();
    unordered_set<int> s;
    cout << "Pair with sum " << target << " (Set): ";
    for(auto num: nums){
        int need = target - num;
        if(s.count(need)){
            cout << "(" << need << ", " << num << ") ";
        }
        s.insert(num);
    }
    cout << endl;
}

void findPairWithGivenSumUsingMap(vector<int> nums, int target){
    map<int, int> m;
    cout << "Pair with sum " << target << " (Map): ";
    for(auto num: nums){
        int need = target - num;
        if(m.find(need) != m.end()){
            cout << "(" << need << ", " << num << ") ";
        }
        m[num] = 1; // Store value and its index
    }
    cout << endl;
}

int majorityElement(vector<int> nums){
    int n = nums.size();
    if(n == 0) return -1;
    int count = 1;
    int currElement = nums[0];
    for(auto num:nums){
        if(currElement != num){
            count--;
        }
        else{
            count++;
        }

        if(count == 0){
            count++;
            currElement = num;
        }
    }
    return currElement;
}

void moveAllZeroesToEnd(vector<int>& nums){
    int index = 0;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] != 0){
            swap(nums[i], nums[index]);
            index++;
        }
    }

    for(auto num:nums){
        cout << num << " " ;
    }
    cout << endl;
}

int smallestMissingPositive(vector<int>& nums){
    int n = nums.size();
    for(int i = 0; i < n; i++){
        // Cycle Sort: Each number x should be at index x-1
        while(nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i]-1]){
            swap(nums[i], nums[nums[i]-1]);
        }
    }

    for(int i = 0; i < n; i++){
        if(nums[i] != i+1){
            return i+1;
        }
    }
    return n+1;
}

int smallestMissingPositiveAlternative(vector<int> nums){
    unordered_set<int> s(nums.begin(), nums.end());
    int i = 1;
    while(true){
        if(s.find(i) == s.end()) return i;
        i++;
    }
}

// User-suggested 1-based indexing approach
int smallestMissingPositiveOneBased(vector<int> nums){
    int n = nums.size();
    // To store value 'n' at index 'n', we need size n+1
    nums.push_back(-1); 
    
    for(int i = 0; i < nums.size(); i++){
        // Place value 'x' at index 'x'
        while(nums[i] > 0 && nums[i] < nums.size() && nums[i] != nums[nums[i]]){
            swap(nums[i], nums[nums[i]]);
        }
    }

    // Ignore index 0, start checking from 1
    for(int i = 1; i < nums.size(); i++){
        if(nums[i] != i){
            return i;
        }
    }
    return nums.size();
}

int equilibriumIndex(vector<int> nums){
    int n = nums.size();
    int totalSum = 0;
    for(auto num:nums){
        totalSum += num;
    }
    int leftSum = 0;
    for(int i = 0; i < n; i++){
        int rightSum = totalSum - leftSum - nums[i];
        if(leftSum == rightSum){
            return i;
        }
        leftSum += nums[i];
    }
    return -1;
}

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, 1);

    // Prefix pass
    for (int i = 1; i < n; i++) {
        res[i] = res[i - 1] * nums[i - 1];
    }

    // Suffix pass
    int suffix = 1;
    for (int i = n - 1; i >= 0; i--) {
        res[i] *= suffix;
        suffix *= nums[i];
    }
    return res;
}

int longestConsecutiveSequence(vector<int> nums){
    unordered_set<int> st(nums.begin(), nums.end());
    int longest = 0;

    for (int num : st) {
        // Only start counting from the beginning of a sequence.
        if (st.find(num - 1) != st.end()) continue;

        int curr = num;
        int len = 1;
        while (st.find(curr + 1) != st.end()) {
            curr++;
            len++;
        }
        longest = max(longest, len);
    }

    return longest;
}

int main(){
    vector<int> nums = {0, 1, 3, 4};
    cout <<"Missing Number: "<< missingNumber(nums, 4) << endl;
    cout <<"Second Largest: "<< secondLargest(nums) << endl;
    vector<int> nums2 = {3, 6 ,2, 1, 8};
    cout <<"Second Largest: "<< secondLargest(nums2) << endl;
    vector<int> nums3 = {0, 1, 2, 0, 1, 2, 2, 1, 0};
    sort012(nums3);
    vector<int> nums4 = {1, -2, 3, 4, -5, 2, 1, 2, -1};
    cout <<"Max Subarray Sum: "<< maxSubarraySum(nums4) << endl;
    vector<int> nums5 = {1, 2, 3, 4, 5};
    cout << "Original: ";
    for(int i: nums5) cout << i << " "; cout << endl;

    cout << "No of Subarray with Sum: " << noOfSubArrayWithSum(nums5, 5) << endl;

    vector<int> numsRight = nums5;
    rightRotate(numsRight, 2);
    cout << "Right Rotated by 2: ";
    for(int i: numsRight) cout << i << " "; cout << endl;

    vector<int> numsLeft = nums5;
    leftRotate(numsLeft, 2);
    cout << "Left Rotated by 2: ";
    for(int i: numsLeft) cout << i << " "; cout << endl;
    findPairWithGivenSum(nums5, 5);
    findPairWithGivenSumUsingMap(nums5, 5);
    vector<int> nums6 = {1, 2, 3, 4, 5, 5, 5, 6, 2};
    cout << "Majority Element: " << majorityElement(nums6) << endl;

    vector<int> nums7 = {0, 1, 0, 2, 5, 0, 1, 2};
    moveAllZeroesToEnd(nums7);

    vector<int> nums8 = {1, 2, 0};
    cout << "Smallest Missing Positive (nums8): " << smallestMissingPositive(nums8) << endl;
    cout << "Alternative method: " << smallestMissingPositiveAlternative({1, 2, 0}) << endl;

    vector<int> nums9 = {3, 4, -1, 1};
    cout << "Smallest Missing Positive (nums9): " << smallestMissingPositive(nums9) << endl;
    cout << "1-Based indexing method: " << smallestMissingPositiveOneBased({3, 4, -1, 1}) << endl;
    subarraySumforNegative(nums9, 5);
    vector<int> nums10 = {1, 2, 3, 0, 3};
    cout << "Equilibrium Index: " << equilibriumIndex(nums10) << endl;

    vector<int> nums11 = {100, 4, 200, 1, 3, 2};
    cout << "Longest Consecutive Sequence: " << longestConsecutiveSequence(nums11) << endl;
}
