class Solution {
public:
    int binsearch(vector<int> &potions, int n,long long success, int spellx){
        int low =0,high = n-1, ans=-1;
        int mid = low + (high -low)/2;
        while(low<=high){
            long long target = potions[mid] * (long long) spellx;
            
            if(target>=success){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
            
            mid = low + (high -low)/2;
        }
        return ans;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        int n = potions.size();
        sort(potions.begin(),potions.end());
        
        for(int i=0;i<spells.size();i++){
            // int x = success/(long long) spells[i];
            int idx = binsearch(potions,n,success,spells[i]);
            // int idx = upper_bound(potions.begin(),potions.end(),x) - potions.begin();
            // cout<<idx<<" ";
            // int target = n - idx;
            if(idx == -1)       ans.push_back(0);
            else                ans.push_back(potions.size()-idx);
        }
        return ans;
    }
};