#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
    HOW BINARY SEARCH WORKS:
    1. Start with the whole array [low, high].
    2. Pick the middle element 'mid'.
    3. If nums[mid] is our target, we are done.
    4. If target is GREATER than nums[mid], move 'low' to mid + 1.
    5. If target is SMALLER than nums[mid], move 'high' to mid - 1.
    6. Repeat until low > high.
*/

int binarySearch(vector<int>& nums, int target) {
  int low = 0;
  int high = nums.size() - 1;

  while (low <= high) {
    // Find the middle point
    int mid = low + (high - low) / 2;

    if (nums[mid] == target) {
      return mid; // Found the index!
    } else if (nums[mid] < target) {
      // Look in the right half
      low = mid + 1;
    } else {
      // Look in the left half
      high = mid - 1;
    }
  }

  return -1; // Not found
}

int main() {
  vector<int> nums = {10, 20, 30, 40, 50, 60, 70, 80, 90};
  int target = 40;

  cout << "Searching for " << target << " in sorted array..." << endl;

  int result = binarySearch(nums, target);

  if (result != -1) {
    cout << "Successfully found at index: " << result << endl;
  } else {
    cout << "Value " << target << " not found in the array." << endl;
  }

  return 0;
}
