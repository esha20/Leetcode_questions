class Solution {
public:
    bool dfs(int node,set<int> &s1,set<int> &s2,vector<bool> &dfsv,vector<vector<int>>& graph,bool &f1){
        dfsv[node]=true;
        if(f1==false)   return false;
        if(s1.empty() && s2.empty()){
            s1.insert(node);
            for(auto i : graph[node])
                s2.insert(i);
        }
        else if(s1.find(node)==s1.end()){
            for(auto i: graph[node]){
                if(s2.find(i) != s2.end())     return false;
                s1.insert(i);
            }
        }
        else{
            for(auto i: graph[node]){
                if(s1.find(i) != s1.end())     return false;
                s2.insert(i);
            }
        }
        for(auto i : graph[node]){
            if(!dfsv[i]){
                f1 = dfs(i,s1,s2,dfsv,graph,f1);
            }
        }
        return f1;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        set<int> s1,s2;
        vector<bool> dfsv(graph.size(),0);
        bool ans,f1=true;
        // s1.insert(0);
        for(int i = 0;i<graph.size();i++){
            if(!dfsv[i]){
                ans = dfs(i,s1,s2,dfsv,graph,f1);
            }
        }
        return ans;
    }
};