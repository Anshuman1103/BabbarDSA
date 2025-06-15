#include <bits/stdc++.h>
using namespace std;

int Ceil(vector<int> v, int target){ // smallest no. in the array >= target
    int ans = -1;
    int low = 0, high = v.size()-1;

    while (low <= high)
    {
        int mid = (low + high)/2;
        if(v[mid] >= target){
            ans = mid;
            high = mid -1;
        }
        else{
            low = mid + 1;
        }
    }
    return v[ans];
}

int Floor(vector<int> v, int target){ // Largest no. in the array <= target
    int ans = -1;
    int low = 0, high = v.size()-1;

    while (low <= high)
    {
        int mid = (low + high)/2;
        if(v[mid] <= target){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return v[ans];
}


int main() {
    vector<int> v = {1,5,10,15,20,30};

    int target = 25;

    cout << "Floor : " << Floor(v, target) << endl;
    cout << "Ceil : " << Ceil(v, target) << endl;
    return 0;
}
