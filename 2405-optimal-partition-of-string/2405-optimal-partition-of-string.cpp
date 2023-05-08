class Solution {
public:
    int partitionString(string s) {
        map<char,int>vis;
        int cnt =1;
        
        for(int i=0;i<s.length();i++){ 
            if(vis[s[i]]){
                cnt++;
                vis.clear();
                vis[s[i]] = 1;
            }
            else{
                vis[s[i]] = 1;
            }
        }
        return cnt;
    }
};