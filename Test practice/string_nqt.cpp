#include<bits/stdc++.h>
using namespace std;

bool checkSameString(string s1, string s2){
    string temp = "";
    for(int i = 0; i < s1.length(); i++){
        if(s1[i] == '#'){
           if(!temp.empty()) {
                temp.pop_back();
            }
        }
        else{
            temp += s1[i];
        }
    }
    return temp == s2;
}

int countMaxA(string str, int l){
    int maxCount = 0;
    int currMax = 0;
    int iterate = l;
    for(auto s : str){
        if(iterate == 0){
            iterate = l;
            currMax = 0;
        }
        if(s == 'a'){
            currMax++;
            maxCount = max(currMax, maxCount);
        }
        iterate--;
    }
    return maxCount;

    // int maxCount = 0;

    // for(int i = 0; i < str.length(); i += l){
    //     int count = 0;

    //     for(int j = i; j < i + l && j < str.length(); j++){
    //         if(str[j] == 'a')
    //             count++;
    //     }

    //     maxCount = max(maxCount, count);
    // }

    // return maxCount;
}

char getOddColorOut(vector<char> &colors){
    unordered_map<char,int> mpp;
    for(int i = 0 ; i < colors.size(); i++){
        mpp[colors[i]]++;
    }
    for(auto item : mpp){
        if(item.second % 2 != 0) return item.first;
    }
    return ' ';
}


// Q4. 🔐 Caesar Cipher / Shift Characters (Frequently Asked)
// Story: A secret message is encrypted by shifting each character by K positions in the alphabet. Decrypt the message by shifting back.
string decrypt(string s, int k) {

    for(int i = 0; i < s.length(); i++) {

        if(islower(s[i])) {
            s[i] = (s[i] - 'a' - k + 26) % 26 + 'a';
        }
        else if(isupper(s[i])) {
            s[i] = (s[i] - 'A' - k + 26) % 26 + 'A';
        }

    }

    return s;
}




int main(){
    string s1 = "ab#c", s2 = "ac";
    cout << checkSameString(s1, s2) << endl;
    cout << countMaxA("abaabaa", 3) << endl;
    vector<char> colors = {'r', 'g', 'b', 'r', 'g', 'b', 'r'};
    cout << getOddColorOut(colors) << endl;
    string s1 = "khoor";
    int k1 = 3;

    string s2 = "LIPPS";
    int k2 = 4;

    cout << decrypt(s1, k1) << endl;
    cout << decrypt(s2, k2);
}