#include <iostream>
#include <set>      // multiset is inside <set>
using namespace std;

/*A multiset is an ordered associative container in C++ that stores multiple elements with duplicate values allowed.

It is implemented as a balanced binary search tree (usually a Red-Black Tree).

Elements are always stored in sorted order (ascending by default).*/

int main() {
    // 🔹 Create a multiset of integers
    multiset<int> ms;

    // 🔹 Insert elements (duplicates allowed)
    ms.insert(10);
    ms.insert(20);
    ms.insert(10);
    ms.insert(30);
    ms.insert(20);

    cout << "Initial multiset (sorted, duplicates allowed): ";
    for (int val : ms) cout << val << " ";
    cout << "\n";

    // 🔹 Count occurrences of a value
    cout << "Count of 10: " << ms.count(10) << "\n";

    // 🔹 Find an element
    auto it = ms.find(20); // Returns iterator to first 20
    if (it != ms.end())
        cout << "Found element: " << *it << "\n";

    // 🔹 Erase ONE occurrence of a value
    if (it != ms.end()) ms.erase(it); // Removes only one '20'
    cout << "After erasing one 20: ";
    for (int val : ms) cout << val << " ";
    cout << "\n";

    // 🔹 Erase ALL occurrences of a value
    ms.erase(10); // Removes every '10'
    cout << "After erasing all 10s: ";
    for (int val : ms) cout << val << " ";
    cout << "\n";

    // 🔹 Lower bound and Upper bound
    // lower_bound(x): first element >= x
    // upper_bound(x): first element > x
    auto lb = ms.lower_bound(20);
    auto ub = ms.upper_bound(20);

    cout << "Lower bound of 20: " << (lb != ms.end() ? to_string(*lb) : "No element") << "\n";
    cout << "Upper bound of 20: " << (ub != ms.end() ? to_string(*ub) : "No element") << "\n";

    // 🔹 Insert duplicate and show that duplicates are stored
    ms.insert(30);
    ms.insert(30);
    cout << "After inserting duplicate 30s: ";
    for (int val : ms) cout << val << " ";
    cout << "\n";

    // 🔹 Clear the multiset
    ms.clear();
    cout << "After clearing, multiset size: " << ms.size() << "\n";

    return 0;
}
