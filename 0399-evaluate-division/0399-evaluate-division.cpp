class Solution {
public:
    
    unordered_map <string, unordered_map<string,double>> buildgraph(vector<vector<string>>& equations, vector<double>& values){
        unordered_map <string, unordered_map<string,double>> adj;
        
        for(int i=0;i<equations.size();i++){
            string u = equations[i][0];
            string v = equations[i][1];
            
            //visualise a graph from a to b meaning a/b is 2 therefor the edge from a to b is 2.0
            adj[u][v] = values[i];
            
            //similarly for graph from b to a , the value will be 1/value
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
        
        vector<double> res; //to store the final ans
        
        //build graph with the vectors provided.
        unordered_map <string, unordered_map<string,double>> adj = buildgraph(equations, values);
        
        //formulate the ans
        for(auto i : queries){
            string u = i[0];
            string v = i[1];
            
            //if the equations vector does not contain any string from the query vector, the ans is -1.0
            if(adj.find(u) == adj.end() || adj.find(v) == adj.end())    res.push_back(-1.0);
            
            //for every valid string, dfs is performed and for that we need a new  visited set everytime.
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