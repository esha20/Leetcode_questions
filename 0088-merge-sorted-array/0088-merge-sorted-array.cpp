class Solution {
public:
    // void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    //     vector<int>ans;
    //     int i=0,j=0;
    //     while(i<m && j<n){
    //         if(nums1[i]<nums2[j]){
    //             ans.push_back(nums1[i]);
    //             i++;
    //         }
    //         else{
    //             ans.push_back(nums2[j]);
    //             j++;
    //         }
    //     }
    //     if(i<m){
    //         while(i<m){
    //             ans.push_back(nums1[i]);
    //             i++;
    //         }
    //     }
    //     if(j<n){
    //     while(j<n){
    //             ans.push_back(nums2[j]);
    //             j++;
    //         }
    //     }
    //     // nums1.clear();
    //     for(int i=0;i<ans.size();i++){
    //         nums1[i] = ans[i];
    //     }
    // }
    
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1,j=n-1,k=m+n-1;
        while(i>=0 && j>=0){
            if(nums1[i]<nums2[j]){
                nums1[k]=nums2[j];
                k--;    j--;
            }
            else{
                nums1[k]=nums1[i];
                k--;    i--;
            }
        }
        while(j>=0){
            nums1[k] = nums2[j];
            k--;
            j--;
        }
    }
};