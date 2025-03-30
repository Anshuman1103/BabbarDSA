#include <iostream>
#include <sstream>  // Required for stringstream
using namespace std;

int main() {
    // string line = "Hello world from C++";
    // stringstream ss(line);  // Load the string into stringstream
    
    // string word;
    // while (ss >> word) {  // Extract words
    //     cout << word << endl;
    // }


    string numbers = "10 20 30 40 50";
    stringstream ss(numbers);
    
    int num;
    while (ss >> num) {  // Extract numbers
        cout << num << " ";  // Processing extracted numbers
    }
    
    return 0;
}
