#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>


using namespace std;

vector<string> findKLengthSubstrings(string s, int k) {
  if (k > s.length() || k > 26)
    return {}; // Optimization: k > 26 impossible for unique chars

  vector<string> result;
  unordered_map<char, int> freq;
  unordered_set<string> seen; // To ensure unique substrings in output if needed

  for (int i = 0; i < s.length(); i++) {
    // Add current character
    freq[s[i]]++;

    // Remove leftmost character once window exceeds size k
    if (i >= k) {
      char leftChar = s[i - k];
      if (--freq[leftChar] == 0) {
        freq.erase(leftChar);
      }
    }

    // Check if window is exactly size k and all characters are unique
    if (i >= k - 1 && freq.size() == k) {
      string sub = s.substr(i - k + 1, k);
      if (seen.find(sub) == seen.end()) {
        result.push_back(sub);
        seen.insert(sub);
      }
    }
  }
  return result;
}

int main() {
  string s = "awaglknagawunagwkwagl";
  int k = 4;
  vector<string> res = findKLengthSubstrings(s, k);

  for (const string &str : res)
    cout << str << " ";
  return 0;
}