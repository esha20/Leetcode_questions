class Solution {
public:
    bool ispossible(vector<int>& piles, int h, long long mid){
        int timecnt = 0;
        if(mid==0)      return false;
        // int rem=0,qt=0;
        for(int i=0;i<piles.size();i++){
                long long qt = piles[i]/mid;
                if(piles[i] % mid != 0) timecnt++;
                timecnt += qt;
            if(timecnt>h)   return false;
        }
    return (timecnt<=h);
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        long long sum=0;
        
        for(int i=0;i<piles.size();i++)     sum+=piles[i];
        
        long long start =0, end = sum, ans =-1;
        long long mid = start +(end-start)/2;
        
        while(start<=end){
            if(ispossible(piles,h,mid)){
                ans = mid;
                end = mid -1;
            }
            else{
                start = mid+1;
            }
            mid = start +(end-start)/2;
        }
        return ans;
    }
};