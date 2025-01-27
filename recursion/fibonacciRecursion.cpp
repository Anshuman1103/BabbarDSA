#include <iostream>
using namespace std;

// Function to calculate Fibonacci number recursively
int fibonacci(int n) {
    if (n <= 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;

    cout << "Enter the number of terms for Fibonacci sequence: ";
    cin >> n;

    cout << "Fibonacci Sequence up to " << n << " terms:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << fibonacci(i) << " ";
    }
    cout << endl;

    return 0;
}
