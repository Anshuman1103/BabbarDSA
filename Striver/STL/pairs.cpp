#include <bits/stdc++.h>
using namespace std;

int main() {
    pair<int, string> p1 = {1, "Apple"};
    pair<char, double> p2('A', 3.14);
    
    cout << p1.first << " " << p1.second << endl;  // Output: 1 Apple
    cout << p2.first << " " << p2.second << endl;  // Output: A 3.14
    

    vector<pair<int, int>> vec = {{1, 2}, {3, 4}, {5, 6}};

    for (auto p : vec)
    cout << p.first << " " << p.second << endl;
    return 0;
}
