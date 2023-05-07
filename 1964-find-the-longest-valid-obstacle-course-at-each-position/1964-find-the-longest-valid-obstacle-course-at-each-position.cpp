class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> ans;
        vector<int>lis;
        
        int n = obstacles.size();
        lis.push_back(obstacles[0]);
        ans.push_back(1);
        
        for(int i=1;i<n;i++){
            // if(lis.size()==0)       ans.push_back(1);
            // else{
                if(obstacles[i]>=lis.back()){
                    lis.push_back(obstacles[i]);
                    ans.push_back(lis.size());
                }
                else{
                    int idx = upper_bound(lis.begin(),lis.end(),obstacles[i])-lis.begin();
                    // cout<<idx;
                    lis[idx]=obstacles[i];
                    ans.push_back(idx+1);
                }
            // }
        }
        return ans;
    }
};