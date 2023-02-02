class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int start =0, end = nums.size()-1;
        int mid = start+(end-start)/2;
        
        // if(nums.size()<3){
        //     if(nums.size() == 2)
        //         return (nums[0]>nums[1])?0:1;
        //     else
        //         return 0;
        // }
        
        while(start<end){
            // if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
            //     return mid;
            if(nums[mid] < nums[mid+1])
                start=mid+1;
            else
                end = mid;
            
            mid = start+(end-start)/2;
        }
        return mid;
    }
};