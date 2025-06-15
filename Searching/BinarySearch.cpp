#include <iostream>
#include <vector>
using namespace std;

int BinarySearch(vector<int> arr, int target){
    int low = 0, high = arr.size() - 1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] == target) return mid;
        else if(arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;

    // if (low > high) return -1;  // Base case: not found

    // int mid = low + (high - low) / 2;

    // if (arr[mid] == target) return mid;           // Target found
    // else if (arr[mid] > target)                   // Search left half
    //     return binarySearchRecursive(arr, low, mid - 1, target);
    // else                                          // Search right half
    //     return binarySearchRecursive(arr, mid + 1, high, target);
}

int main() {
    vector<int> arr = {2,6,4,8,7,10};
    int key;
    cout << "Enter element to search: ";
    cin >> key;

    int result = BinarySearch(arr, key);
    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found in array." << endl;
    }
    return 0;
}