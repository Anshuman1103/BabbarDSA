#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

/* 
1. Decimal to Binary Conversion
Problem: Convert integer N to binary without built-in functions.
Sample Input: 10 | Sample Output: 1010
*/
int decimalToBinary(int n) {
    // int n; cin>>n;
    // string ans="";
    // if(n==0) ans="0";
    // while(n>0){
    //     ans=char('0'+(n%2))+ans;
    //     n/=2;
    // }
    // cout<<ans;
    if(n == 0) return 0;
    vector<int> temp;
    while(n > 0){
        temp.push_back(n % 2);
        n = n / 2;
    }
    int ans = 0;
    int power = 0;
    for(int i = temp.size()-1; i >= 0; i--){
        ans += temp[i] * pow(10, power);
        power++;
    }
    return ans;
}

/* 
2. Binary to Decimal
Problem: Convert a binary number (as integer) to decimal.
Sample Input: 1011 | Sample Output: 11
*/
int binaryToDecimal(int n) {
    int decimal = 0, base = 1;
    while (n > 0) {
        int lastDigit = n % 10;
        decimal += lastDigit * base;
        n /= 10;
        base *= 2;
    }
    return decimal;
}

/* 
3. Check Power of Two
Problem: Check if a number is a power of 2.
Sample Input: 16 | Sample Output: YES
*/
string isPowerOfTwo(int n) {
    if (n <= 0) return "NO";
    return (n & (n - 1)) == 0 ? "YES" : "NO";
}

/* 
4. Count Set Bits
Problem: Count number of 1s in binary representation.
Sample Input: 13 | Sample Output: 3
*/
int countSetBits(int n) {
    int count = 0;
    while (n > 0) {
        n = n & (n - 1);
        count++;
    }
    return count;

    // int n; cin>>n;
    // int cnt=0;

    // while(n){
    //     cnt += n & 1;
    //     n >>= 1;
    // }

    // cout << cnt;
}

/* 
5. Reverse Bits of Number
Problem: Reverse binary digits of a number.
Sample Input: 6 (110) | Sample Output: 3 (011)
*/
int reverseBits(int n) {
    int reversed = 0;
    while (n > 0) {
        reversed = (reversed << 1) | (n & 1);
        n >>= 1;
    }
    return reversed;
}

/* 
6. Check Binary Palindrome
Problem: Check if binary representation of number is palindrome.
Sample Input: 9 (1001) | Sample Output: YES
*/
string isBinaryPalindrome(int n) {
    // string bin = decimalToBinary(n);
    // string revBin = bin;
    // reverse(revBin.begin(), revBin.end());
    // return bin == revBin ? "YES" : "NO";

    int bin = decimalToBinary(n);
    int originalBin = bin;
    int reversedBin = 0;
    
    // Mathematical integer reversal
    while (bin > 0) {
        int lastDigit = bin % 10;
        reversedBin = reversedBin * 10 + lastDigit;
        bin /= 10;
    }
    
    return originalBin == reversedBin ? "YES" : "NO";
}

/* 
7. XOR of All Numbers from 1 to N
Problem: Find XOR sum from 1 to N.
Sample Input: 5 | Sample Output: 1
*/
int xorOneToN(int n) {
    if (n % 4 == 0) return n;
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    return 0;
}

/* 
8. Find Unique Element (Others appear twice)
Problem: Given array where every element appears twice except one, find it.
Sample Input: 5, {1, 2, 3, 2, 1} | Sample Output: 3
*/
int findUnique(vector<int>& arr) {
    int unique = 0;
    for (int x : arr) {
        unique ^= x;
    }
    return unique;
}

/* 
9. Swap Two Numbers Without Temp
Problem: Swap two numbers using XOR.
Sample Input: 5 9 | Sample Output: 9 5
*/
void swapXOR(int &a, int &b) {
    if (a == b) return;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

/* 
10. Check Even or Odd Using Bitwise
Problem: Check whether a number is even or odd using bitwise.
Sample Input: 7 | Sample Output: ODD
*/
string checkEvenOdd(int n) {
    return (n & 1) ? "ODD" : "EVEN";
}

int main() {
    cout << "1. Decimal to Binary (10): " << decimalToBinary(10) << endl;
    cout << "2. Binary to Decimal (1011): " << binaryToDecimal(1011) << endl;
    cout << "3. Is Power of Two (16): " << isPowerOfTwo(16) << endl;
    cout << "4. Count Set Bits (13): " << countSetBits(13) << endl;
    cout << "5. Reverse Bits (6): " << reverseBits(6) << endl;
    cout << "6. Is Binary Palindrome (9): " << isBinaryPalindrome(9) << endl;
    cout << "7. XOR 1 to N (5): " << xorOneToN(5) << endl;
    
    vector<int> arr = {1, 2, 3, 2, 1};
    cout << "8. Find Unique {1, 2, 3, 2, 1}: " << findUnique(arr) << endl;
    
    int a = 5, b = 9;
    swapXOR(a, b);
    cout << "9. Swap 5, 9: " << a << " " << b << endl;
    
    cout << "10. Check Even/Odd (7): " << checkEvenOdd(7) << endl;
    
    return 0;
}
