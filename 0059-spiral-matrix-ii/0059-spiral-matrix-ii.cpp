class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix (n, vector<int> (n,0));
        // vector<int> ans;
        int cnt =0;
        int r =0, c=0, lr=n-1, lc= n-1;
        
        while(cnt < n*n){
            //first row
            for(int i=c;i<=lc;i++){
                // ans.push_back(cnt);
                matrix[r][i]=cnt+1;
                cnt++;
            }
            r++;
            
            //last col
            for(int i=r;i<=lr;i++){
                // ans.push_back(cnt);
                matrix[i][lc] = cnt+1;
                cnt++;
            }
            lc--;
            
            if(r>lr || c>lc)    break;
            
            //last row
            for(int i=lc;i>=c;i--){
                matrix[lr][i]=cnt+1;
                cnt++;
            }
            lr--;
            
            //first col
            for(int i=lr;i>=r;i--){
                matrix[i][c]= cnt+1;
                cnt++;
            }
            c++;
        }
        return matrix;
    }
};