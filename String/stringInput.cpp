#include <iostream>
#include <string> // It's good practice to include this for string tasks
#include <limits> // Required for the robust version of ignore

using namespace std;

int main() {
    // const int SIZE = 100;
    // char buffer[SIZE];

    // cout << "Enter a line of text: ";
    // cin.getline(buffer, SIZE);

    // cout << "You entered: " << buffer << endl;


    // Single Word Input
    string str1;
    cout << "Enter first word: ";
    cin >> str1;
    cout << "str1: " << str1 << endl;
    // FIX: Clear the buffer
    // This ignores everything until the next newline
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // to enter string
    string str2;
    cout << "Enter a full line: ";
    getline(cin, str2);
    cout << "str2: " << str2 << endl;
    return 0;
    return 0;
}
