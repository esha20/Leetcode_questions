class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int cnt =0;
        int r =0, c = 0, lr = row-1, lc = col-1;
        
        vector<int> ans;
        
        while (cnt < row*col){
            
            //print starting row
            for(int i=c;i<=lc;i++){
                ans.push_back(matrix[r][i]);
                cnt++;
            }
            r++;
            
            //printing last col
            for(int i=r;i<=lr;i++){
                ans.push_back(matrix[i][lc]);
                cnt++;
            }
            lc--;
            
            if(r > lr || c>lc)      break;
            
            //printing last row
            for(int i=lc;i>=c;i--){
                ans.push_back(matrix[lr][i]);
                cnt++;
            }
            lr--;

            //printing first col
            for(int i=lr;i>=r;i--){
                ans.push_back(matrix[i][c]);
                cnt++;
            }
            c++;
        }
        return ans;
    }
};