#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Helper: Convert to lowercase
string toLowerCase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

// Helper: Remove spaces
string removeSpaces(string str) {
    string result = "";
    for (char c : str) {
        if (c != ' ') result += c;
    }
    return result;
}

/*
Q1. Reverse Words in a Sentence
Problem: Reverse the order of words in a sentence.
Sample Input: "Hello World from TCS"
Sample Output: "TCS from World Hello"
*/
string reverseWords(string str) {
    stringstream ss(str);
    string word;
    vector<string> words;
    while (ss >> word) {
        words.push_back(word);
    }
    string result = "";
    for (int i = words.size() - 1; i >= 0; i--) {
        result += words[i];
        if (i != 0) result += " ";
    }
    return result;
}

/*
Q2. Check Anagram
Problem: Check if two strings are anagrams of each other.
Sample Input: s1 = "listen", s2 = "silent"
Sample Output: YES
*/
bool checkAnagram(string s1, string s2) {
    if (s1.length() != s2.length()) return false;
    s1 = toLowerCase(s1);
    s2 = toLowerCase(s2);
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
}

/*
Q3. Longest Substring Without Repeating Characters
Problem: Find length of longest substring with no repeating characters.
Sample Input: s = "abcabcbb"
Sample Output: 3
*/
int longestSubstring(string str) {
    unordered_set<char> st;
    int left = 0, maxLength = 0;
    for (int right = 0; right < str.length(); right++) {
        while (st.count(str[right])) {
            st.erase(str[left]);
            left++;
        }
        st.insert(str[right]);
        maxLength = max(maxLength, right - left + 1);
    }
    return maxLength;
}

/*
Q4. Run-Length Encoding
Problem: Compress string using run-length encoding.
Sample Input: s = "aaabbbccddddee"
Sample Output: "a3b3c2d4e2"
*/
string runLengthEncoding(string str) {
    if (str.empty()) return "";
    string result = "";
    int count = 1;
    for (int i = 0; i < str.length(); i++) {
        if (i + 1 < str.length() && str[i] == str[i + 1]) {
            count++;
        } else {
            result += str[i] + to_string(count);
            count = 1;
        }
    }
    return result;
}

/*
Q5. Check Palindrome String
Problem: Check if a given string is a palindrome (ignore spaces and case).
Sample Input: s = "A man a plan a canal Panama"
Sample Output: YES
*/
bool isPalindromeAdvanced(string str) {
    string cleaned = toLowerCase(removeSpaces(str));
    string reversed = cleaned;
    reverse(reversed.begin(), reversed.end());
    return cleaned == reversed;
}

/*
Q6. First Non-Repeating Character
Problem: Find the first character that appears only once in a string.
Sample Input: s = "aabbcdeeff"
Sample Output: c
*/
char firstNonRepeatingChar(string str) {
    unordered_map<char, int> freq;
    for (char c : str) freq[c]++;
    for (char c : str) {
        if (freq[c] == 1) return c;
    }
    return '\0'; // Return null if not found
}

/*
Q7. String Rotation Check
Problem: Check if string s2 is a rotation of string s1.
Sample Input: s1 = "abcde", s2 = "cdeab"
Sample Output: YES
*/
bool isRotation(string s1, string s2) {
    if (s1.length() != s2.length()) return false;
    string temp = s1 + s1;
    return temp.find(s2) != string::npos;
}

/*
Q8. Count and Say
Problem: Generate the Nth term of the Count and Say sequence.
1 -> "1", 2 -> "11", 3 -> "21", 4 -> "1211", 5 -> "111221"
*/
string countAndSay(int n) {
    if (n == 1) return "1";
    string s = "1";
    for (int i = 2; i <= n; i++) {
        string temp = "";
        int count = 1;
        for (int j = 0; j < s.length(); j++) {
            if (j + 1 < s.length() && s[j] == s[j + 1]) {
                count++;
            } else {
                temp += to_string(count) + s[j];
                count = 1;
            }
        }
        s = temp;
    }
    return s;
}

/*
Q9. Remove All Duplicate Characters
Problem: Remove all duplicate characters keeping only first occurrence.
Sample Input: s = "geeksforgeeks"
Sample Output: "geksfor"
*/
string removeDuplicates(string str) {
    string result = "";
    unordered_set<char> seen;
    for (char c : str) {
        if (seen.find(c) == seen.end()) {
            seen.insert(c);
            result += c;
        }
    }
    return result;
}

/*
Q10. Longest Common Prefix
Problem: Find the longest common prefix among array of strings.
Sample Input: ["flower", "flow", "flight"]
Sample Output: "fl"
*/
string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";
    string prefix = strs[0];
    for (int i = 1; i < strs.size(); i++) {
        while (strs[i].find(prefix) != 0) {
            prefix = prefix.substr(0, prefix.length() - 1);
            if (prefix.empty()) return "";
        }
    }
    return prefix;
}

int main() {
    cout << "--- String Practice Problems (Q1-Q10) ---\n" << endl;

    // Q1
    cout << "Q1. Reverse Words: \"Hello World from TCS\" -> " 
         << reverseWords("Hello World from TCS") << endl;

    // Q2
    cout << "Q2. Check Anagram: \"listen\", \"silent\" -> " 
         << (checkAnagram("listen", "silent") ? "YES" : "NO") << endl;

    // Q3
    cout << "Q3. Longest Substring: \"abcabcbb\" -> " 
         << longestSubstring("abcabcbb") << endl;

    // Q4
    cout << "Q4. Run-Length Encoding: \"aaabbbccddddee\" -> " 
         << runLengthEncoding("aaabbbccddddee") << endl;

    // Q5
    cout << "Q5. Check Palindrome (Advanced): \"A man a plan a canal Panama\" -> " 
         << (isPalindromeAdvanced("A man a plan a canal Panama") ? "YES" : "NO") << endl;

    // Q6
    char fnr = firstNonRepeatingChar("aabbcdeeff");
    cout << "Q6. First Non-Repeating: \"aabbcdeeff\" -> " << (fnr ? string(1, fnr) : "None") << endl;

    // Q7
    cout << "Q7. String Rotation: \"abcde\", \"cdeab\" -> " 
         << (isRotation("abcde", "cdeab") ? "YES" : "NO") << endl;

    // Q8
    cout << "Q8. Count and Say (N=5): " << countAndSay(5) << endl;

    // Q9
    cout << "Q9. Remove Duplicates: \"geeksforgeeks\" -> " 
         << removeDuplicates("geeksforgeeks") << endl;

    // Q10
    vector<string> strs = {"flower", "flow", "flight"};
    cout << "Q10. Longest Common Prefix: [\"flower\", \"flow\", \"flight\"] -> " 
         << longestCommonPrefix(strs) << endl;

    return 0;
}