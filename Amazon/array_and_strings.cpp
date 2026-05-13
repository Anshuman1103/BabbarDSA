#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Topic 1 — Arrays & Strings (your strength, but Amazon-flavoured versions)

// Q1. Maximum consecutive ON servers after K flips (reported: Amazon OA SDE-2,
// 2024) Amazon has a cluster of servers where '1' = ON and '0' = OFF. You can
// flip a contiguous sequence of servers up to K times. Find the maximum
// consecutive ON servers possible. Input:  server_states = "1001", k = 2
// Output: 4   →  flip the "00" to get "1111"

// Input:  server_states = "11101010110011", k = 2
// Output: ?   →  your job to find the longest window

// Pattern: Sliding window. Expand right, track number of 0s inside window,
// shrink left when 0s exceed

int filpingServer(vector<int> &nums, int k) {
  int n = nums.size();
  int maxi = 0, count0 = 0, low = 0;

  for (int high = 0; high < n; high++) {
    // 1. Expand the window: If we hit a 0, count it
    if (nums[high] == 0) {
      count0++;
    }

    // 2. Shrink the window: If 0s exceed K, move 'low' until we drop a 0
    while (count0 > k) {
      if (nums[low] == 0) {
        count0--;
      }
      low++;
    }

    // 3. Update result: window size is (high - low + 1)
    maxi = max(maxi, high - low + 1);
  }
  return maxi;
}

int flippingServersString(string s, int k) {
  int n = s.length();
  int maxi = 0, count0 = 0, low = 0;

  for (int high = 0; high < n; high++) {
    if (s[high] == '0')
      count0++;
    while (count0 > k) {
      if (s[low] == '0')
        count0--;
      low++;
    }
    maxi = max(maxi, high - low + 1);
  }
  return maxi;
}

// Q2. Minimum items to remove so any K items don't exceed threshold (reported:
// Amazon OA SDE-2, 2024) Determine the minimum number of items to remove from
// an array of prices so that the sum of prices for any k items does not exceed
// a threshold. If total items are less than k, no removal is needed. Input:
// prices = [3, 2, 1, 4, 6, 5], k = 3, threshold = 14 Output: 1   →  remove 6;
// now any 3 items sum ≤ 14

// Pattern: Sort descending. The top-K items are the worst case. Keep removing
// largest until the top-K sum ≤ threshold.

int thresholdRemove(vector<int> &nums, int k, int threshold) {
  int n = nums.size();
  if (n < k || k == 0)
    return 0;

  long long sum = 0;
  int low = 0;
  sort(nums.begin(), nums.end());
  for (int high = 0; high < n; high++) {
    // 1. Expand window
    sum += nums[high];

    // 2. Shrink window if size exceeds k
    if (high - low + 1 > k) {
      sum -= nums[low];
      low++;
    }

    // 3. Check condition ONLY when window size is exactly k
    if (high - low + 1 == k && sum > threshold) {
      return n - high;
    }
  }
  return 0;
}

// Q3. Distribute parcels — minimise the maximum (reported: Amazon OA, Aug 2024)
// Amazon wants to distribute extra parcels among delivery agents to minimise
// the maximum number of parcels any single agent carries. Given parcels[] and
// extra_parcels, find the minimum possible maximum. Input:  parcels = [7, 5, 1,
// 9, 1], extra_parcels = 25 Output: 10 Pattern: Binary search on the answer.
// Check if it's possible to distribute all extra parcels such that no agent
// exceeds mid. Classic "minimise the maximum" binary search template.

// Q4. DNA sequence — count pattern occurrences (reported: Amazon OA 2025, 2026)
// DNA Sequence Analysis has been reported by multiple July 2025 OA takers as a
// new question type. Count how many times a pattern string appears in a genome
// string (overlapping allowed). Input:  genome = "AAGAATTCGAATTC", pattern =
// "GAATTC" Output: 2 Input:  genome = "AAAA", pattern = "AA" Output: 3   →
// overlapping: positions 0,1,2

int dnaCount(string genome, string pattern) {
  int count = 0;
  int n = genome.length();
  for (int i = 0; i < n; i++) {
    if (genome[i] == pattern[0]) {
      int k = i;
      int j = 0;
      while (k < n && j < pattern.length()) {
        if (genome[k] == pattern[j]) {
          k++;
          j++;
        } else {
          break;
        }
        if (j == pattern.length()) {
          count++;
        }
      }
    }
  }
  return count;
}

int main() {
  vector<int> nums = {0, 1, 0, 0, 1};
  int k = 2;
  cout << "Maximum consecutive ON servers is: " << filpingServer(nums, k)
       << endl;

  vector<int> prices = {3, 2, 1, 4, 6, 5};
  cout << "Minimum items to remove is: " << thresholdRemove(prices, 3, 14)
       << endl;

  string genome = "AAGAATTCGAATTC";
  string pattern = "GAATTC";
  cout << "Number of occurrences is: " << dnaCount(genome, pattern) << endl;

  string genome2 = "AAABAAACCCCCAA";
  string pattern2 = "AA";
  cout << "Number of occurrences is: " << dnaCount(genome2, pattern2) << endl;
}