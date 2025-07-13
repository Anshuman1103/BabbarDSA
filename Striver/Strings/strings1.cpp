#include<bits/stdc++.h>
using namespace std;

void inputWord(){
    string str;
    cout << "Enter a string (no spaces): ";
    cin >> str; // it might hinder with getline
    //getline(cin,str);
    cout << "You entered: " << str << endl;
}

void inputSentence(){
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);
    cout << "You entered: " << sentence << endl;
}

string removeDuplicates(string str) {
    unordered_set<char> seen;
    string result = "";

    for (char ch : str) {
        if (seen.find(ch) == seen.end()) {
            seen.insert(ch);
            result += ch;
        }
    }
    return result;
}

int main() {
    inputSentence();

    return 0;
}