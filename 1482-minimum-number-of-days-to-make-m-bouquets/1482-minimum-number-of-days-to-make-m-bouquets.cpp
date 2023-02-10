class Solution {
public:
    bool isposs(vector<int>& arr, int mid, int m, int k){
        int flwcnt = 0, bqcnt =0;
        for(int i=0;i<arr.size();i++){
            if(arr[i] <= mid){
                flwcnt++;
                if(flwcnt == k ){
                    bqcnt ++;
                    flwcnt =0;
                    if(bqcnt == m)      return true;
                }  
            }
            else{
                flwcnt =0;
            }
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        // if(m*k > bloomDay.size())       return -1;
        
        int start = 0, end = INT_MIN, ans = INT_MAX;
        
        for(int i=0;i<bloomDay.size();i++){
            // start = min (start , bloomDay[i]);
            end = max(end, bloomDay[i]);
        }
        
        int mid = start +(end-start)/2;
        
        while(start<=end){
            if(isposs(bloomDay, mid , m , k)){
                ans =mid;
                end = mid -1;
            }
            else{
                start = mid +1;
            }
            mid = start+(end-start)/2;
            }
        return ans== INT_MAX? -1 : ans;
    }
};