class Solution {
public:
    
    unordered_map <string, unordered_map<string,double>> buildgraph(vector<vector<string>>& equations, vector<double>& values){
        unordered_map <string, unordered_map<string,double>> adj;
        
        for(int i=0;i<equations.size();i++){
            string u = equations[i][0];
            string v = equations[i][1];
            
            adj[u][v] = values[i];
            adj[v][u] = 1.0/values[i];
        }
        return adj;
    }
    
    void dfs(unordered_set<string> &vis,string src, string &dest, double &ans, double temp,unordered_map <string, unordered_map<string,double>> &adj){
        if(vis.find(src) != vis.end())      return;
        //meaning already visited
        
        vis.insert(src);
        if(src==dest){
            ans = temp;
            return;
        }
        
        for(auto i : adj[src])
            dfs(vis,i.first,dest,ans,temp*i.second,adj);
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        vector<double> res;
        unordered_map <string, unordered_map<string,double>> adj = buildgraph(equations, values);
        
        for(auto i : queries){
            string u = i[0];
            string v = i[1];
            
            if(adj.find(u) == adj.end() || adj.find(v) == adj.end())    res.push_back(-1.0);
            else{
                unordered_set<string> vis;
                double temp = 1.0, ans = -1.0;
                dfs(vis,u,v,ans, temp, adj);
                res.push_back(ans);
            }
        }
        return res;
    }
};