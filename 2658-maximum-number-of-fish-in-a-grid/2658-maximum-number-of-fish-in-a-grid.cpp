class Solution {
public:
    int bfs(vector<vector<int>>& grid, int i, int j,vector<vector<bool>> &visited){
        visited[i][j] = true;
        queue<pair<int,int>> q;
        q.push({i,j});
        int ans = grid[i][j];
        int R = grid.size();
        int C = grid[0].size();
        while(!q.empty()){
            pair<int,int> frontnode = q.front();
            q.pop();
            int row = frontnode.first;
            int col = frontnode.second;
            
            //for left element
            if(row >= 0 && row < R && col-1 >= 0 && col-1 < C && grid[row][col-1]!=0 && visited[row][col-1] == false ){
                q.push({row,col-1});
                ans += grid[row][col-1];
                visited[row][col-1] = true;
            }
            
            //for right element 
            if(row >= 0 && row < R && col+1 >= 0 && col+1 < C && grid[row][col+1]!=0 && visited[row][col+1] == false ){
                q.push({row,col+1});
                ans += grid[row][col+1];
                visited[row][col+1] = true;
            }
            
            //for top element
            if(row-1 >= 0 && row-1 < R && col>= 0 && col< C && grid[row-1][col]!=0 && visited[row-1][col] == false ){
                q.push({row-1,col});
                ans += grid[row-1][col];
                visited[row-1][col] = true;
            }
            
            //for bottom element
            if(row+1 >= 0 && row+1 < R && col>= 0 && col< C && grid[row+1][col]!=0 && visited[row+1][col] == false ){
                q.push({row+1,col});
                ans += grid[row+1][col];
                visited[row+1][col] = true;
            }
        }
        return ans;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        
        vector<vector<bool>> visited (r,vector<bool>(c,false));
        int maxfish =0;
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j] != 0 && visited[i][j] == false){
                    maxfish = max(maxfish,bfs(grid,i,j,visited));
                }
            }
        }
        return maxfish;
    }
};