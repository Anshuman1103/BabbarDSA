#include <bits/stdc++.h>
using namespace std;

// The learned  code is in the javaPractice folder

// int lowerBound(vector<int>& vec, int x) {
//     int low = 0, high = vec.size();
//     while (low < high) {
//         int mid = (low + high) / 2;
//         if (vec[mid] < x)
//             low = mid + 1;
//         else
//             high = mid;
//     }
//     return low;
// }

// int upperBound(vector<int>& vec, int x) {
//     int low = 0, high = vec.size();
//     while (low < high) {
//         int mid = (low + high) / 2;
//         if (vec[mid] <= x)
//             low = mid + 1;
//         else
//             high = mid;
//     }
//     return low;
// }


int main() {
    vector<int> v = {1, 2, 4, 4, 4, 5, 6, 8};

    int target = 4;

    // lower_bound returns an iterator to the first element >= target
    auto lb = lower_bound(v.begin(), v.end(), target);

    // upper_bound returns an iterator to the first element > target
    auto ub = upper_bound(v.begin(), v.end(), target);

    cout << "Lower bound of " << target << " is at index: " << lb - v.begin() << endl;
    cout << "Upper bound of " << target << " is at index: " << ub - v.begin() << endl;

    return 0;
}
