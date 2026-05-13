#include <iostream>
#include <vector>
using namespace std;

// Question 1: Container With Most Water
// Problem: You are given an integer array height of length n. There are n
// vertical lines drawn such that the two endpoints of the ith line are (i, 0)
// and (i, height[i]).
int containMostWater(vector<int> &height) {
  if (height.size() < 2)
    return 0;

  long long water = 0;
  int left = 0, right = (int)height.size() - 1;

  while (left < right) {
    long long h = min(height[left], height[right]);
    long long w = right - left;
    water = max(water, w * h);

    if (height[left] < height[right])
      left++;
    else
      right--;
  }
  return (int)water;
}

int buyAndSellStock(vector<int> &prices) {
  if (prices.size() < 2)
    return 0;
  int buy = prices[0];
  int profit = 0;
  for (size_t i = 1; i < prices.size(); i++) {
    profit = max(profit, prices[i] - buy);
    buy = min(buy, prices[i]);
  }
  return profit;
}

// void mergeIntervals(vector<vector<int>> &intervals){
//     sort(intervals.begin(), intervals.end());
//     vector<vector<int>> ans;
//     int i = 0;
//     int n = intervals.size();
//     while(i < n){
//         if(i == n-1)
//         if(intervals[i][0] != intervals[i+1][0]){
//             ans.push_back(interval[i]);
//         }
//     }

// }

int missingNumber(vector<int> &nums) {
  int n = nums.size();
  int sum = (n * (n + 1)) / 2;
  int currSum = 0;
  for (auto num : nums) {
    currSum += num;
  }
  return sum - currSum;
}

int missingNumberXor(const vector<int> &nums) {
  int n = (int)nums.size();
  int x = 0;
  for (int i = 0; i <= n; i++)
    x ^= i;
  for (int v : nums)
    x ^= v;
  return x;
}

int main() {
  vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  cout << "Container With Most Water: " << containMostWater(height) << endl;
  vector<int> prices = {7, 1, 5, 3, 6, 4};
  cout << "Buy and Sell Stock: " << buyAndSellStock(prices) << endl;
  vector<vector<int>> intervals = {{1, 3},   {2, 6}, {8, 10},
                                   {15, 18}, {2, 7}, {11, 13}};
  // mergeIntervals(intervals);
  vector<int> nums = {3, 0, 1, 4, 2};
  cout << "Missing Number: " << missingNumber(nums) << endl;
  return 0;
}