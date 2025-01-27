 #include<iostream>
using namespace std;
 
long long int binarySearch(int n){
        int s = 0;
        int e = n ;
        int ans = -1;
        long long int mid = s + (e-s)/2;
        while(s<=e){

            mid = s + (e-s)/2;

            long long int sq = mid * mid;

            if(sq == n){
                return mid;
            }

            if(sq < n ){
                s = mid + 1;
                ans = mid;
            }

            else    e = mid - 1;
        }
    return ans;
}

double precision(int n, int precision, int intValue){
    double ans = intValue;
    double factor = 1;
    for (int i = 0; i < precision; i++)
    {
        factor = factor/10;
        for (double j = ans; j*j < n; j = j + factor )
        {
            ans = j;
        }
        
    }
    return ans;
    
}

int main(){

    int n;
    cin >> n;
    int temp = binarySearch(n);
    cout << "Answer is: " << precision(n, 3, temp);
    
}