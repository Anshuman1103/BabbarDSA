#include <iostream>
#include <climits>

using namespace std;

/**
 * 1. Get i-th Bit
 * Problem: Check if the i-th bit of a number is set (1) or not (0).
 * Sample Input: n = 5 (101), i = 1 | Sample Output: 0
 * Sample Input: n = 5 (101), i = 2 | Sample Output: 1
 */
int getIthBit(int n, int i) {
    int mask = (1 << i);
    return (n & mask) > 0 ? 1 : 0;
}

/**
 * 2. Set i-th Bit
 * Problem: Set the i-th bit of a number to 1.
 * Sample Input: n = 5 (101), i = 1 | Sample Output: 7 (111)
 */
int setIthBit(int n, int i) {
    int mask = (1 << i);
    return (n | mask);
}

/**
 * 3. Clear i-th Bit
 * Problem: Clear the i-th bit of a number (set to 0).
 * Sample Input: n = 7 (111), i = 1 | Sample Output: 5 (101)
 */
int clearIthBit(int n, int i) {
    int mask = ~(1 << i);
    return (n & mask);
}

/**
 * 4. Toggle i-th Bit
 * Problem: Invert the i-th bit of a number (0 to 1 or 1 to 0).
 * Sample Input: n = 5 (101), i = 1 | Sample Output: 7 (111)
 * Sample Input: n = 5 (101), i = 2 | Sample Output: 1 (001)
 */
int toggleIthBit(int n, int i) {
    int mask = (1 << i);
    return (n ^ mask);
}

/**
 * 5. Remove Last Set Bit
 * Problem: Clear the rightmost set bit of a number.
 * Sample Input: n = 12 (1100) | Sample Output: 8 (1000)
 */
int removeLastSetBit(int n) {
    return (n & (n - 1));
}

/**
 * 6. Check Power of 2
 * Problem: Determine if a number is a power of 2 using bitwise.
 * Sample Input: n = 16 | Sample Output: YES
 */
string isPowerOfTwo(int n) {
    if (n <= 0) return "NO";
    return (n & (n - 1)) == 0 ? "YES" : "NO";
}

/**
 * 7. Count Set Bits
 * Problem: Count the number of bits set to 1 in a number.
 * Sample Input: n = 15 (1111) | Sample Output: 4
 */
int countSetBits(int n) {
    int count = 0;
    while (n > 0) {
        n = n & (n - 1);
        count++;
    }
    return count;
}

/**
 * 8. Find Position of Rightmost Set Bit
 * Problem: Find the position (1-based) of the first set bit from right.
 * Sample Input: n = 12 (1100) | Sample Output: 3
 */
int posRightmostSetBit(int n) {
    if (n == 0) return 0;
    // (n & -n) gives the rightmost set bit as a power of 2
    int bitValue = (n & -n);
    int pos = 1;
    while (bitValue > 1) {
        bitValue >>= 1;
        pos++;
    }
    return pos;
}

/**
 * 9. Check for Opposite Signs
 * Problem: Check if two integers have opposite signs.
 * Sample Input: a = 100, b = -100 | Sample Output: YES
 */
string haveOppositeSigns(int a, int b) {
    // XOR of signs will be negative if signs are different
    return ((a ^ b) < 0) ? "YES" : "NO";
}

/**
 * 10. Absolute Value using Bitwise
 * Problem: Find the absolute value of an integer without branching.
 * Sample Input: n = -5 | Sample Output: 5
 */
int absBitwise(int n) {
    int const mask = n >> (sizeof(int) * CHAR_BIT - 1);
    return (n + mask) ^ mask;
}

int main() {
    cout << "--- Bit Manipulation Questions ---" << endl;
    
    cout << "1. Get 2nd bit of 5 (101): " << getIthBit(5, 2) << endl;
    cout << "2. Set 1st bit of 5 (101): " << setIthBit(5, 1) << endl;
    cout << "3. Clear 1st bit of 7 (111): " << clearIthBit(7, 1) << endl;
    cout << "4. Toggle 1st bit of 5 (101): " << toggleIthBit(5, 1) << endl;
    cout << "5. Remove last set bit of 12 (1100): " << removeLastSetBit(12) << endl;
    cout << "6. Is 16 power of two? " << isPowerOfTwo(16) << endl;
    cout << "7. Count set bits in 15: " << countSetBits(15) << endl;
    cout << "8. Position of rightmost set bit in 12 (1100): " << posRightmostSetBit(12) << endl;
    cout << "9. Do 100 and -100 have opposite signs? " << haveOppositeSigns(100, -100) << endl;
    cout << "10. Absolute value of -5: " << absBitwise(-5) << endl;

    return 0;
}