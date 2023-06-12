class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int row = grid.size();
        int col = grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(row,vector<int>(col,0));
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        
        int dx[4] = {0,0,-1,1};
        int dy[4] = {-1,1,0,0};
        int time =-1;
        
        while(!q.empty()){
            int z = q.size();
            while(z--){
                
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                
                for(int x=0;x<4;x++){
                    int nx = i + dx[x];
                    int ny = j + dy[x];
                    
                    if(nx>=0 && nx<row && ny>=0 && ny<col && vis[nx][ny]==0 && grid[nx][ny]==1){
                        vis[nx][ny]=1;
                        q.push({nx,ny});
                        grid[nx][ny]=2;
                    }
                }
            }
            time++;
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(vis[i][j]!=1 && grid[i][j]==1)    return -1;
            }
        }
        if(time==-1)        return 0;
        return time;
    }
};