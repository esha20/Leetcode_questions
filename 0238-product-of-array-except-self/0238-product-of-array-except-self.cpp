class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int prod =1, cnt =0; bool flag = false;
        vector<int> vect;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0)      prod*=nums[i];
            else                cnt++;
        }
        
        for(int i=0;i<nums.size();i++){
            if(cnt ==0)     vect.push_back(prod/nums[i]);
            else if(cnt==1){
                if(nums[i]==0)  vect.push_back(prod);
                
                else            vect.push_back(0);
            }
            else{
                vect.push_back(0);
            }
        }
        return vect;
    }
};