class Solution {
public:
    int mod = 1e9+7;
    int  goodstrlen(int len, int zero, int one,vector<int> &dp){
        //exactly 0 has reached
        //this is a good str
        if(len ==0) return 1;
        
        //not a good string because the choices we have made have reached us beyond limits.
        //thus no good str found.
        if(len<0)   return 0;
        
        if(dp[len] != -1)   return dp[len];
        
        //if 0 or less has not reached , then we either can place 0(zero number of times) or 1(one number of times) 
        long long sum = ((goodstrlen(len-zero,zero,one,dp) +  goodstrlen(len-one, zero, one,dp)) % mod);
        return  dp[len]=sum;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        int ans=0;
        vector<int> dp(high+1, -1);
        for (int i = low;i<=high;i++){
            ans = (ans +  goodstrlen(i,zero,one,dp)) % mod;
        }
        return ans;
    }
};