#include<bits/stdc++.h>
using namespace std;

bool isValid(string str) {
    stack<char> st;
    for(char ch : str){
        if(ch == '(' || ch == '[' || ch == '{'){
            st.push(ch);
        }
        else{
            char top = st.top();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }
    if(st.empty()) return true;
    else return false;
}

int main() {
    // 1. Unmatched Closing (Should Crash/Fail)
    cout << "Test Case 1: \")()(\" -> " << (isValid(")()(") ? "Valid\n" : "Invalid\n");
    
    // 2. Simple Closing (Should Crash/Fail)
    cout << "Test Case 2: \"}\" -> " << (isValid("}") ? "Valid\n" : "Invalid\n");
    
    // 3. Unmatched/Mismatched Brackets (Will Fail)
    cout << "Test Case 3: \"([)]\" -> " << (isValid("([)]") ? "Valid\n" : "Invalid\n");
    
    // 4. Balanced Substring with Unclosed Final Bracket (Will Fail)
    cout << "Test Case 4: \"(())[\" -> " << (isValid("(())[") ? "Valid\n" : "Invalid\n");

    return 0;
}