#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

bool isPrime(int n){
    if(n <= 1) return false;
    for(int i = 2; i <= sqrt(n) ; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

void printAllPrime(int n){
    vector<bool> prime(n+1, true);
    prime[0] = prime[1] = false;
    for(int i = 2; i <= sqrt(n); i++){
        if(prime[i]){
            for(int j = i*i; j <= n; j+=i){
                prime[j] = false;
            }
        }
    }

    for(int i = 0; i <= n; i++){
        if(prime[i]){
            cout << i << " ";
        }
    }
    cout << endl;
}

int getGCD(int a, int b) {
    if (b == 0) return a;
    return getGCD(b, a % b);
}

pair<int, int> getLCMandHCF(int a, int b) {
    int hcf = getGCD(a, b);
    int lcm = (a * b) / hcf;
    return {lcm, hcf};
}


// ✅ Important takeaway
// We do not compute the factorial.
// Instead we count how many times the factor 5 appears in N!.
int trailingZeroInFactorial(int n){
    int ans = 0;
    // while(n > 0){
    //     n /= 5;
    //     ans += n;
    // }
    for(int i = 5; i <= n; i *= 5)
        ans += n / i;
    return ans;
}

//(A^B) % M
long long fastExponentiation(long long base, long long power, long long mod){
    long long ans = 1;
    base %= mod;
    while(power > 0){
        if(power & 1){
            ans = (ans * base) % mod;
        }
        base = (base * base) % mod;
        power >>= 1;
    }
    return ans;
}

bool checkArmstrong(int n){
    int digit = 0;
    int temp = n;
    while(temp > 0){
        temp /= 10;
        digit++;
    }
    temp = n;
    int ans = 0;
    while(temp > 0){
        ans += (int)pow(temp % 10, digit); // pow return double so we cast it to int
        temp /= 10;
    }
    if(ans == n) return true;
    return false;
}

void printAllDivisor(int n){
    vector<int> ans;
    for(int i = 1; i <= sqrt(n); i++){
        if(n % i == 0){
            ans.push_back(i);
            if(i!=n/i){
                ans.push_back(n / i);
            }
        }
    }
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}

int greatestPrimeFactor(int n){
    return  0;
}

// Count numbers divisible by A or B
// What the problem says
// Count numbers from 1 to N divisible by A or B.
int countDivisibleByAorB(int n, int a, int b){
    int gcd = getGCD(a, b);
    int lcm = (a * b) / gcd;
    return (n/a) + (n/b) - (n/lcm);
}

// Digital Root
// What the problem says
// Keep summing digits until one digit remains.
// 9875
// 9+8+7+5 = 29
// 2+9 = 11
// 1+1 = 2
int digitalRoot(int n){
    int ans = 0;
    while(n > 10){
        int temp = n;
        int sum = 0;
        while(temp > 0){
            sum += (temp % 10);
            temp /= 10;
        }
        n = sum;
    }
    return n;
}

bool isPerfectNumber(int n){
    int sum = 1;
    for(int i = 2; i < sqrt(n); i++){
        if(n % i == 0){
            sum += i;
        }
        if(i*i != n){
            sum += (n/i);
        }
    }
    return sum == n;
}

void printFibonacci(int n){
    int a = 0 , b = 1;
    cout<< "Fibonacci : " << a << " "<< b << " ";
    for(int i = 2; i < n; i++){
        int c = a + b;
        a = b;
        b = c;

        cout << c << " ";
    }
    return;
}

int factorial(int n){
    int ans = 1;
    for(int i = n; i > 0; i--){
        ans *= i;
    }
    return ans;
}

void numberToWords(int n){
    
}


int main(){
    cout << isPrime(10) << endl;
    printAllPrime(50);
    pair<int, int> result = getLCMandHCF(48, 18);
    cout << "LCM: " << result.first << ", HCF: " << result.second << endl;
    cout << "Trailing Zero in 50!: " << trailingZeroInFactorial(50) << endl;
    cout << "Fast Exponentiation: " << fastExponentiation(2, 20, 1000000007) << endl;
    cout << "Check Armstrong: " << checkArmstrong(153) << endl;
    cout << "Check Armstrong: " << checkArmstrong(123) << endl;
    printAllDivisor(12);
    cout << "Count Divisible by A or B: " << countDivisibleByAorB(10, 2, 3) << endl;
    cout << "Digital Root: " << digitalRoot(9875) << endl;
    cout << "Perfect Number: " << isPerfectNumber(6) << endl;
    printFibonacci(10);
    cout << "Factorial of 5: " << factorial(5) << endl;
}