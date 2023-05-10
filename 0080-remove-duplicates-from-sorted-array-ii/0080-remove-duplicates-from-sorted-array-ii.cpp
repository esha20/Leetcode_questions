class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //sliding window approach 
        //for border case
        if(nums.size()<=2)      return nums.size();
        
        int j=2,i=0;
        while(j<nums.size()){
            if(nums[i]!=nums[j])
            {
                nums[i+2] = nums[j];
                i++;
            }
            j++;
        }
        return i+2;
    }
};