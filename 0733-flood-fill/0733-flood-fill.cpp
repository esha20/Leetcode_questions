class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& images, int sr, int sc, int color) {
        
        int row = images.size();
        int col = images[0].size();
        
        queue<pair<int,int>> q;
        q.push({sr,sc});
        vector<vector<bool>>vis(row,vector<bool>(col,0));
        vis[sr][sc]=1;
        
        int oldcolor=images[sr][sc];
        images[sr][sc]=color;
        
        int dx[4] = {0,0,-1,1};
        int dy[4] = {-1,1,0,0};
        
        while(!q.empty()){
            
            auto i = q.front().first;
            auto j = q.front().second;
            
            q.pop();
            
            for(int ni=0;ni<4;ni++){
                int nx = i + dx[ni];
                int ny = j + dy[ni];
                
                if(nx>=0 && nx<row && ny>=0 && ny<col && !vis[nx][ny] && images[nx][ny]==oldcolor){
                    q.push({nx,ny});
                    vis[nx][ny]=1;
                    images[nx][ny]=color;
                }
            }
        }
        
        return images;
    }
};