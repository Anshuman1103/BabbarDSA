#include <bits/stdc++.h>
using namespace std;

// bool isPresent(vector<string> result, string str){
//     for(auto val : result){
//         if(val == str) return true;
//     }
//     return false;
// }

// vector<string> generateSubstrings(string str, int start, int end, vector<string> &result){
//     if(start == str.length()) return result;

//     if(end == str.length()){
//         return generateSubstrings(str, start+1, start+1, result);
//     }

//     string sub = str.substr(start, end - start + 1 );

//     if(!isPresent(result, sub)){
//         result.push_back(sub);
//     }

//     return generateSubstrings(str, start, end+1, result);

// }

void substring(string str, int start , int end, unordered_set<string> &st){
    if(start == str.length()) return;
    if(end == str.length()){
        substring(str, start+1, start+1, st);
        return;
    }

    string sub = str.substr(start, end - start + 1);
    st.insert(sub);

    substring(str, start , end+1, st);
}

vector<string> generate(string str){
    unordered_set<string> st;
    substring(str, 0, 0, st);
    return vector<string> (st.begin(), st.end());
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input); // Taking input including spaces
    cout << "You entered: " << input << endl;

    vector<string> result = generate(input);

    sort(result.begin(), result.end());

    cout << "The output is " << endl;
    for(auto val : result){
        cout << val << endl;
    }
    return 0;
}