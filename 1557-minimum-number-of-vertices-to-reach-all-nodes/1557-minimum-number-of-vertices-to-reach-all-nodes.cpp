class Solution {
public:
    void dfs(int node,vector<bool> &dfsv,vector<int>adj[]){
        dfsv[node]= 1;
        for(auto i : adj[node]){
            if(!dfsv[i])       dfs(i,dfsv,adj);
        }
    }
    void topo(int i,stack<int>&s,vector<bool>&vis,vector<int> adj[]){
        vis[i]=1;
        for(auto x:adj[i]){
            if(!vis[x])
            topo(x,s,vis,adj);
        }
        s.push(i);
    }
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        vector<bool>vis(n,false);
        vector<int> adj[n];
        stack<int>s;
        
        for(auto i : edges){
            adj[i[0]].push_back(i[1]);
        }
        
        //topological sort
        for(int i=0;i<n;i++){
            if(!vis[i])     topo(i,s,vis,adj);
        }
        
        //dfs
        vector<bool>dfsv(n,0);
        while(s.size()){
            int front = s.top();
            s.pop();
            if(!dfsv[front]){
                ans.push_back(front);
                dfs(front,dfsv,adj);
            }
        }
        return ans;
    }
};