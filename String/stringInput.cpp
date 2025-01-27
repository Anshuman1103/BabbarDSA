#include <iostream>

using namespace std;

int main() {
    const int SIZE = 100;
    char buffer[SIZE];

    cout << "Enter a line of text: ";
    cin.getline(buffer, SIZE);

    cout << "You entered: " << buffer << endl;


    // to enter string
    string str;
    getline(cin, str);
    cout << str<<endl;

    return 0;
}
