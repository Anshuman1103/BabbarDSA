#include <iostream>
#include <string>
#include <sstream> // Required for stringstream
#include <vector>

using namespace std;

/**
 * StringStream Tutorial:
 * A stringstream associates a string object with a stream, 
 * allowing you to read from or write to the string as if it were a stream (like cin or cout).
 */

int main() {

    // string line = "Hello world from C++";
    // stringstream ss(line);  // Load the string into stringstream
    
    // string word;
    // while (ss >> word) {  // Extract words
    //     cout << word << endl;
    // }


    // string numbers = "10 20 30 40 50";
    // stringstream ss(numbers);
    
    // int num;
    // while (ss >> num) {  // Extract numbers
    //     cout << num << " ";  // Processing extracted numbers
    // }
    

    cout << "===== C++ StringStream Tutorial =====" << endl;

    // ---------------------------------------------------------
    // PROBLEM 1: Count the number of words in a sentence.
    // Concept: Use stringstream to extract words separated by spaces.
    // ---------------------------------------------------------
    cout << "\n--- Problem 1: Word Counting ---" << endl;
    string sentence = "Coding is fun and stringstream makes it easy";
    stringstream ss1(sentence); // Initialize stream with the string
    string word;
    int wordCount = 0;

    while (ss1 >> word) { // Extracts one word at a time (skips whitespace)
        wordCount++;
        cout << "Found word: " << word << endl;
    }
    cout << "Total Words: " << wordCount << endl;


    // ---------------------------------------------------------
    // PROBLEM 2: Extract integers from a mixed string.
    // Concept: Try to extract an int; if it fails, clear the error and skip the char.
    // ---------------------------------------------------------
    cout << "\n--- Problem 2: Integer Extraction ---" << endl;
    string mixed = "Prices: 10, 20, 30 dollars";
    stringstream ss2(mixed);
    string temp;
    int number;

    cout << "Numbers found: ";
    while (!ss2.eof()) {
        if (ss2 >> number) { // Try to extract an integer
            cout << number << " ";
        } else {
            ss2.clear(); // Clear the error flag if extraction failed
            ss2 >> temp;  // Consume the non-numeric part
        }
    }
    cout << endl;


    // ---------------------------------------------------------
    // PROBLEM 3: Convert String to Number and vice versa
    // Concept: Using streams for safe type casting.
    // ---------------------------------------------------------
    cout << "\n--- Problem 3: Type Conversion ---" << endl;
    
    // String to Double
    string s = "123.45";
    stringstream ss3(s);
    double dValue;
    ss3 >> dValue;
    cout << "String to Double: " << dValue + 10 << " (Added 10)" << endl;

    // Int to String
    int n = 500;
    stringstream ss4;
    ss4 << n; // Put the number into the stream
    string resultStr = ss4.str(); // Get the string back
    cout << "Int to String: " << resultStr << " (Length: " << resultStr.length() << ")" << endl;


    // ---------------------------------------------------------
    // PROBLEM 4: Parse Comma-Separated Values (CSV)
    // Concept: Use getline() with a custom delimiter (',').
    // ---------------------------------------------------------
    cout << "\n--- Problem 4: CSV Parsing ---" << endl;
    string csvData = "John,Doe,25,New York";
    stringstream ss5(csvData);
    string field;

    cout << "Parsing data: " << endl;
    while (getline(ss5, field, ',')) { // Read until the next comma
        cout << "| " << field << " ";
    }
    cout << "|" << endl;


    cout << "\n=====================================" << endl;
    return 0;
}
