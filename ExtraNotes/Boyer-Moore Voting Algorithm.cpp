#include <vector>
using namespace std;

// to find majority element in an array

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int candidate = nums[0];
        
        // Find the candidate for majority element
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }

        // Verify the candidate
        count = 0;
        for (int num : nums) {
            if (num == candidate) {
                count++;
            }
        }

        if (count > n / 2) {
            return candidate;
        }

        // Since the problem guarantees a majority element, we don't need to handle the case
        // where there is no majority element.
        return -1;
    }
};
