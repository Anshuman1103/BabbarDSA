#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> st;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n; i++){//first pointer
            int j = i + 1;//second pointer
            int k = n - 1;// last pointer
            while(i < k){
                int l = k - 1;// second last pointer
                while(j < l){
                    cout << nums[i] << endl;
                    cout << nums[j] << endl;
                    cout << nums[l] << endl;
                    cout << nums[k] << endl<<endl;
                    int sum = nums[i] + nums[j] + nums[k] + nums[l];
                    if(sum > target){//decreasing the sum
                        l--;
                    }
                    else if(sum < target){//increasing the sum
                        j++;
                    }
                    else{
                        //sum == target
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        st.insert(temp);
                        l--;
                        j++;
                        while(j<l && nums[j] ==nums[j-1]) j++;
                        while(j<l && nums[l] == nums[l+1]) l--;
                    }
                }
                k--;
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {  // Loop through each row
        for (const auto& elem : row) { // Loop through each element in the row
            cout << elem << " ";
        }
        cout << endl;  // New line after each row
    }
}

int main() {

    vector<int> arr = {-3,-1,0,2,4,5};
    int target = 2;

    vector<vector<int>> ans = fourSum(arr,target);
    printMatrix(ans);

    
    cout << endl;
    return 0 ;
}