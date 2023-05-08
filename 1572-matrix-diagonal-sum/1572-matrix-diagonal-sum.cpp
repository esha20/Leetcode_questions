class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int diasum = 0;
        int r = mat.size();
        int j=0, k=r-1;
        for (int i=0;i<r;i++){
            diasum += mat[i][j];
            diasum += mat[i][k];
            j++;k--;
        }
        if(r%2!=0)  diasum-=mat[r/2][r/2];
        return diasum;
    }
};