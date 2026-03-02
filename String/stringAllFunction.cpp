#include<iostream>
#include<cctype> // Required for built-in functions like toupper and tolower

using namespace std;

int stringLength(char str[]){
    int count = 0;
    for (int  i = 0; str[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

void reverseString(char str[], int n){
    int s = 0;
    int e = n-1;
    while (s<e)
    {
        swap(str[s++], str[e--]);
    }
    cout<<"Reverse : "<<str<<endl;
}

char toUpperCase(char ch) {
    if (ch >= 'a' && ch <= 'z') {
        return ch - 'a' + 'A';
    }
    return ch;
}

char toLowerCase(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return ch - 'A' + 'a';
    }
    return ch;
}

int palindromeString(char str[], int n) {
    int s = 0;
    int e = n - 1;
    while (s <= e) {
        if (toLowerCase(str[s]) != toLowerCase(str[e])) {
            return 0;
        }
        else {
            s++;
            e--;
        }
    }
    return 1;
}

int main() {
    char str[20];
    cout << "Enter the text:" << endl;
    cin >> str;
    cout << "You entered: " << str << endl;

    int len = stringLength(str);
    cout << "Length: " << len << endl;

    // Palindrome check (now case-insensitive)
    if (palindromeString(str, len)) {
        cout << str << " is a palindrome (case-insensitive)." << endl;
    } else {
        cout << str << " is not a palindrome." << endl;
    }

    // Demonstrate manual character conversion
    char test = 'b';
    cout << "Manual toUpperCase('" << test << "'): " << toUpperCase(test) << endl;
    
    char test2 = 'K';
    cout << "Manual toLowerCase('" << test2 << "'): " << toLowerCase(test2) << endl;

    // Demonstrate BUILT-IN character conversion (from <cctype>)
    cout << "\n--- Built-in Functions (<cctype>) ---" << endl;
    cout << "Built-in toupper('m'): " << (char)toupper('m') << endl;
    cout << "Built-in tolower('P'): " << (char)tolower('P') << endl;

    reverseString(str, len);

    return 0;
}