class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col= matrix[0].size();
        int row_ind= 0;
        int col_ind = col-1;
        while(row_ind<row && col_ind>=0){
            int ele = matrix[row_ind][col_ind];
            if(target==ele)
            {
                return true;
            }
            if(target<ele)
            {
                col_ind--;
            }
            if(target>ele)
            {
                row_ind++;
            }
        }
        return false;
    }
};