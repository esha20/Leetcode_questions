class Solution {
public:
//     int numberOfSubarrays(vector<int>& nums, int k) {
        
//         int i=0,j=0,cnt =0,ans=0;
//         //cout<<nums[j]%2;
//         while(j<nums.size()){
//             if(cnt == k){
//                 ans++;
//                 if(nums[i]%2!=0) cnt--;
//                 i++; j--;
//             }
//             else{
//                 if(nums[j]%2!=0)    cnt++;
//             }
//             j++;
//         }
//         if(cnt==k){
//             ans++;
//         }
//         return ans;
//     }
    
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        
        vector<int> odds;
        odds.push_back(-1);
        for(int i=0;i<n;i++){
            if(nums[i]%2!=0){
                odds.push_back(i);
            }
        }
        odds.push_back(n);
        
        int i=0,j=k+1, ans=0;
        while(j<odds.size()){
            int sum = (odds[i+1] -1 - odds[i]) + (odds[j]-1-odds[j-1]);
            int mul = (odds[i+1] -1 - odds[i]) * (odds[j]-1-odds[j-1]);
            ans+=sum + mul + 1;
            i++;j++;
        }
        return ans;
    }
};