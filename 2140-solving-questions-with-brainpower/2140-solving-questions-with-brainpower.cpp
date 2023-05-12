class Solution {
public:
    long long solve(int i, vector<long long> &dp, vector<vector<int>>& q){
        if(i>=q.size())     return 0;       //meaning we are out of bound already 
        if(dp[i]!=-1)       return dp[i];   //meaning the most points upto this index is already computed
        
        long long ans= 0;
        
        //here we have two options. Either include the current element and skip the brainpower no. of elements to                 recurrsively add the  points or not include it at all and skip to the next element.  
        ans = max(q[i][0] + solve(i+q[i][1]+1, dp , q)  , solve(i+1, dp, q));
        dp[i] = ans;
        return ans;
    }
    long long mostPoints(vector<vector<int>>& questions) {
        long long n = questions.size();
        vector<long long>dp(n+1,-1);
        return solve(0,dp,questions);
    }
};