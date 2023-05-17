class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefixprod=1,maxprefixprod = INT_MIN,suffixprod = 1, maxsuffixprod = INT_MIN;
        for(int i=0;i<nums.size();i++){
            
            if(prefixprod==0)    prefixprod =1;
            
            prefixprod *= nums[i];
            maxprefixprod = max(prefixprod, maxprefixprod);
        }
        for(int i=nums.size()-1;i>=0;i--){
            
            if(suffixprod==0)   suffixprod =1;
            
            suffixprod *= nums[i];
            maxsuffixprod = max(suffixprod, maxsuffixprod);
        }
        
        int maxi = max(maxprefixprod,maxsuffixprod);
        return maxi;
    }
};