class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        
        int row = grid.size();
        int col = row;
        int ans=0;
        map<vector<int>,int> mp;
        
        //sare rows ko map mei add kar diya 
        for(int i=0;i<row;i++) mp[grid[i]]++;
        
        //columns ko iterate karo
        for(int j=0;j<col;j++){
            vector<int> vect;
            
            //col ki banao vector
            for(int i=0;i<row;i++){
                vect.push_back(grid[i][j]);
            }
            
            //check karo agar yeh same vector row mei thi toh ans + freq of that vect occurrance
            //agar sirf ans ++ karte toh galt ata kyuki its possible to have identical row wale vectors.
            if(mp.find(vect)!=mp.end())     ans+=mp[vect];
        }
        return ans;
    }
};