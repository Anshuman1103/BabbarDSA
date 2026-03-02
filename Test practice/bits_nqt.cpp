#include<bits/stdc++.h>
using namespace std;

// Q1. 💻 Decimal to Binary Toggle (Actual TCS Question)
// Story: Convert decimal to binary. Toggle all bits only AFTER the most significant bit (keep MSB same, flip the rest). Print the decimal value.
// Input:
// 10
// Output:
// 13
// Explanation: 10 = 1010. MSB=1 (keep). Rest = 010 → toggle → 101. Final = 1101 = 13
// Constraints: 1 ≤ N ≤ 1000
// Pattern: Binary string → keep first char → flip rest → convert back
// Pro Tip: This is a variation of the toggle question. Read carefully — sometimes they toggle ALL bits, sometimes only after MSB.

int toggleAfterMSB(int n)
{
    int msb = 1;

    while (msb <= n)
        msb <<= 1;

    msb >>= 1;

    int mask = msb - 1;

    return n ^ mask;
}

// Q2. 🔢 Binary to Decimal Conversion (Frequently Asked)
// Story: A student is given a binary string as input. Convert it to its decimal equivalent and print it.
// Input:
// 1010
// Output:
// 10
// Input 2:
// 11111111
// Output 2:
// 255
// Constraints: 1 ≤ len(binary_string) ≤ 32

int binaryToDecimal(string binary)
{
    int decimal = 0;

    for(char bit : binary)
    {
        decimal = decimal * 2 + (bit - '0');
    }

    return decimal;
}

// Q4. 🔢 Number to Words (Actual TCS Question)
// Story: Convert a number to its English word representation. For example 1234 = "One Thousand Two Hundred Thirty Four".
// Input:
// 1234
// Output:
// One Thousand Two Hundred Thirty Four
// Input 2:
// 20
// Output 2:
// Twenty
// Constraints: 0 ≤ N ≤ 9999

string ones[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
string teens[] = {"Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
string tens[] = {"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};

void numberToWords(int n)
{
    if(n == 0)
    {
        cout << "Zero";
        return;
    }

    if(n >= 1000)
    {
        cout << ones[n/1000] << " Thousand ";
        n %= 1000;
    }

    if(n >= 100)
    {
        cout << ones[n/100] << " Hundred ";
        n %= 100;
    }

    if(n >= 20)
    {
        cout << tens[n/10] << " ";
        n %= 10;
    }
    else if(n >= 10)
    {
        cout << teens[n-10] << " ";
        n = 0;
    }

    if(n > 0)
        cout << ones[n];
}


int main(){
    cout << toggleAfterMSB(10) << endl;
    cout << toggleAfterMSB(6) << endl;
    cout << binaryToDecimal("1010") << endl;
    cout << binaryToDecimal("11111111") << endl;
    numberToWords(1234);
}