#include<algorithm>
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int i = 0;
        int j = 0;
        int k = 0;
        vector<int> arr(m+n);
        
        while(i < (m-n) && j < n){
            if(nums1[i] > nums2[j]){
                arr[k] = nums2[j];
                k++;
                j++;
            }
            else if(nums1[i] < nums2[j]){
                arr[k] = nums1[i];
                k++;
                i++;
            }
            else if( nums1[i] == nums2[j]){
                arr[k] = nums1[i];
                k++;
                i++;
            }
            
        }
        while(i < m) {
            arr[k++] = nums1[i++];
        }

        while(j < n) {
            arr[k++] = nums2[j++];
        }

        for(int i = 0, k = 0; i < m && k < m; i++,k++){
            nums1[i] = arr[k];
        }
    }
};