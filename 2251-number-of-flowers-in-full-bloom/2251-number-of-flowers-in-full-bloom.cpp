class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        
        int n = flowers.size();
        vector<int> start,e;
        
        for(int i=0;i<n;i++){
            start.push_back(flowers[i][0]);
            e.push_back(flowers[i][1]);
        }
        
        sort(start.begin(),start.end());
        sort(e.begin(),e.end());
       
        vector<int> ans;
        for(auto p : people){
            int s = upper_bound(start.begin(), start.end(), p)-start.begin();
            int l = lower_bound(e.begin(), e.end(), p)-e.begin();
            int count = s - l;
            ans.push_back(count);
        }
        return ans;
    }
};