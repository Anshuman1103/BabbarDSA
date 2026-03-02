#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// 1. Basic Queries
void demonstrateBasicQueries(string str) {
    cout << "--- Basic Queries ---" << endl;
    cout << "Length (.length()): " << str.length() << endl;
    cout << "Size (.size()): " << str.size() << endl;
    cout << "Is empty? (.empty()): " << (str.empty() ? "Yes" : "No") << endl;
    cout << "Capacity (.capacity()): " << str.capacity() << endl;
    cout << "Max Size (.max_size()): " << str.max_size() << "\n" << endl;
}

// 2. Element Access
void demonstrateElementAccess(string str) {
    cout << "--- Element Access ---" << endl;
    cout << "Access at index 1 ([1]): " << str[1] << endl;
    cout << "Access at index 7 ([7]): " << str[7] << endl;
    cout << "Access at index 7 (.at(7)): " << str.at(7) << endl;
    cout << "Front char (.front()): " << str.front() << endl;
    cout << "Back char (.back()): " << str.back() << "\n" << endl;
}

// 3. Modifiers (Modification)
void demonstrateModifiers() {
    cout << "--- Modifiers ---" << endl;
    string str = "Hello";
    
    // Append
    str.append(", World!");
    cout << "After .append(): " << str << endl;
    
    str += " How are you?";
    cout << "After +=: " << str << endl;

    // push_back / pop_back
    str.push_back('?');
    cout << "After .push_back('?'): " << str << endl;
    str.pop_back();
    cout << "After .pop_back(): " << str << endl;

    // Insert
    str.insert(5, " Dear");
    cout << "After .insert(5, \" Dear\"): " << str << endl;

    // Erase
    str.erase(5, 5); // Erase 5 characters starting from index 5
    cout << "After .erase(5, 5): " << str << endl;

    // Replace
    str.replace(0, 5, "Hi"); // Replace "Hello" with "Hi"
    cout << "After .replace(0, 5, \"Hi\"): " << str << "\n" << endl;
}

// 4. String Operations
void demonstrateStringOperations() {
    cout << "--- String Operations ---" << endl;
    string str = "Hi, World! How are you?";
    
    // Substring
    string sub = str.substr(4, 5); // Start at index 4, length 5
    cout << "Substring .substr(4, 5): " << sub << endl;

    // Find
    size_t found = str.find("World");
    if (found != string::npos) {
        cout << "'World' found at index: " << found << endl;
    }

    // Compare
    string s1 = "Apple";
    string s2 = "Banana";
    if (s1.compare(s2) < 0) {
        cout << s1 << " comes before " << s2 << endl;
    } else {
        cout << s2 << " comes before " << s1 << "\n" << endl;
    }
}

// 5. Conversions & Extra
void demonstrateConversions() {
    cout << "--- Conversions & Extra ---" << endl;
    
    // Int to string
    int num = 123;
    string numStr = to_string(num);
    cout << "Int to string (to_string): " << numStr << endl;

    // String to int
    string sToInt = "456";
    int backToNum = stoi(sToInt);
    cout << "String to int (stoi): " << backToNum << endl;

    // Swap
    string x = "First", y = "Second";
    x.swap(y);
    cout << "After .swap(): x=" << x << ", y=" << y << endl;
}

int main() {
    string str = "Hello, World!";

    cout << "--- Original String ---" << endl;
    cout << "String: " << str << "\n" << endl;

    // Calling refactored functions
    demonstrateBasicQueries(str);
    demonstrateElementAccess(str);
    demonstrateModifiers();
    demonstrateStringOperations();
    demonstrateConversions();

    return 0;
}
