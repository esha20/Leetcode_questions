class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        vector<int> power(nums.size());
        power[0]=1;
        for(int i=1;i<nums.size();i++){
            power[i] = (power[i-1]*2) % (int)(1e9+7);
        }
        
        int low =0,high=nums.size()-1;
        int subseq=0;
        while(low<=high){
            if(nums[low]+nums[high] > target)   high--;
            else{
                subseq+=power[high - low];
                subseq %= (int)(1e9+7);
                low++;
            }
        }
        return subseq;
    }
};