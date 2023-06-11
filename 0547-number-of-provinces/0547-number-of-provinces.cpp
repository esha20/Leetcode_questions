class Solution {
public:
    
    void dfs(vector<int> adj[],int node,vector<bool> &vis){
        vis[node]=1;
        for(auto i : adj[node]){
            if(!vis[i]){
                dfs(adj,i,vis);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<int> adj[n];
        
        for (int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && arr[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        vector<bool> vis(n,0);
        int count=0;
        
        for(int k=0;k<n;k++){
            if(!vis[k]){
                count++;
                dfs(adj,k,vis);
            }
        }
        return count;
    }
};