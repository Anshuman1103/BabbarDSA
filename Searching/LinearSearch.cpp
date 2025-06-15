#include <iostream>
#include <vector>
using namespace std;

int linearSearch(const vector<int>& arr, int key) {
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] == key) {
            return static_cast<int>(i); // Return index if found
        }
    }
    return -1; // Not found
}

int main() {
    vector<int> arr = {10, 23, 45, 70, 11, 15};
    int key;
    cout << "Enter element to search: ";
    cin >> key;

    int result = linearSearch(arr, key);
    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found in array." << endl;
    }
    return 0;
}