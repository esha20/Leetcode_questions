class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row= matrix.size();
        int col=matrix[0].size();
        int i=row;
        while(i--)
        {
            if(target==matrix[i][0])
                return true;
            
            if(target>matrix[i][0])
            {
                for(int j=0;j<col;j++)
                {
                    if(target==matrix[i][j])
                        return true;
                }
            }
        }
        return false;
    }
};