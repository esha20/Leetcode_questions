class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col= matrix[0].size();
        int row_ind= 0;
        int col_ind = col-1;
        
        while(row_ind<row && col_ind>=0){
            int ele = matrix[row_ind][col_ind];
            //starting from the last element of the first row.
            
            
            if(target==ele)
            {
                return true;
            }
            
            
            if(target<ele)
            {
                //target smaller, not in same col since the columns are sorted but can be in same row.
                col_ind--;
            }
            if(target>ele)
            {
                //target larger, can be in the same col but not in the same row since they are sorted.
                row_ind++;
            }
        }
        return false;
    }
};