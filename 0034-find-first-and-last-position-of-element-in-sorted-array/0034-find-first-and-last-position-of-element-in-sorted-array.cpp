class Solution {
public:
    int firstOcc(vector<int>& nums, int target){
        int start =0, end = nums.size()-1;
        int mid = start +(end-start)/2;
        int ans2 = -1;
        while(start<=end){
            if(target==nums[mid]){
                end = mid-1;
                ans2 = mid;
            }
            if(target<nums[mid])
                end = mid -1;
            else if(target>nums[mid])
                start = mid+1;
            mid = start +(end-start)/2;
        }
        return ans2;
    }
    int lastOcc(vector<int>& nums, int target){
        int start =0, end = nums.size()-1;
        int mid = start +(end-start)/2;
        int ans = -1;
        while(start<=end){
            if(target==nums[mid]){
                start=mid+1;
                ans = mid;
            }
            if(target<nums[mid])
                end = mid -1;
            else if(target>nums[mid])
                start = mid+1;
            
            mid = start +(end-start)/2;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2);
        ans[0]=firstOcc(nums, target);
        ans[1]=lastOcc(nums, target);
        return ans;
    }
};