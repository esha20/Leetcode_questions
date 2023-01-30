class Solution {
public:
    //iterative solution
//     int search(vector<int>& nums, int target) {
//         int start =0 , end = nums.size()-1;
//         int mid = start+(end-start)/2;
//         int ans=-1;
//         while(start<=end){
//             if(target == nums[mid]){
//                 ans=mid;
//                 break;
//             }
//             else if(nums[mid]>target)
//                 end = mid-1;
//             else
//                 start=mid+1;
            
//             mid = start +(end-start)/2;
//         }
//         return ans;
//     }

    //recurrsive solution
    void solve(vector<int>& nums, int target, int start, int end, int &ans){
        
        if(start>end)
            return;
        
        int mid = start+(end-start)/2;
        
        if(target == nums[mid])
            ans=mid;
        
        else if(target>nums[mid]){
            solve(nums, target, mid+1, end,ans);
        }
        else{
            solve(nums, target, start, mid-1,ans);
        }
    }
    int search(vector<int>& nums, int target) {
        
        int start =0,end = nums.size()-1,ans=-1;
        solve(nums, target, start, end, ans);
        
        return ans;
    }
};