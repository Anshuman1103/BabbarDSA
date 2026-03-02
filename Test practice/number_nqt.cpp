#include<bits/stdc++.h>
using namespace std;

// Q1. 🔢 Toggle Bits After MSB (Actual TCS Question — Real Exam 2023)
// Story: Joseph is learning digital logic. He is given a positive integer. Convert it to binary, toggle ALL bits including the MSB, and print the resulting positive integer.
// Input:
// 10
// Output:
// 5
// Explanation: 10 in binary = 1010. Toggle all bits → 0101 = 5
// Input 2:
// 6
// Output 2:
// 1
// Explanation: 6 = 110, toggle → 001 = 1
// Constraints: 1 ≤ N ≤ 100
int toggleBits(int n){
    int bits = 0;
    int temp = n;
    while (temp > 0){
        bits++;
        temp >>= 1;
    }
    
    int mask = (1 << bits) - 1;
    return n ^ mask;
}

// Q2. 🍬 Candy Jar Problem (Actual TCS Question)
// Story: A JAR has capacity N candies. Minimum K candies must always remain. Customers buy candies one at a time. When candies reach K, refill to N. Given customer input, output candies sold and remaining. Print "INVALID INPUT" if order exceeds available.
// Input (N=10, K=5):
// 3
// Output:
// NUMBER OF CANDIES SOLD: 3
// NUMBER OF CANDIES LEFT: 7
// Input 2:
// 6
// Output 2:
// INVALID INPUT

void candyJar(int k, int n, int x){
    if( x < n - k && x < n){
        cout << "NUMBER OF CANDIES SOLD: " << x << endl;
        cout << "NUMBER OF CANDIES LEFT: " << n - x << endl;
    }
    else{
        cout << "INVALID INPUT" << endl;    
    }
}

int main(){
    cout << toggleBits(10) << endl;
    cout << toggleBits(6) << endl;
    candyJar(5, 10, 3);
    candyJar(5, 10, 6);
}