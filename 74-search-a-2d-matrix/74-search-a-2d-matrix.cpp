class Solution {
public:
    
    //APPROACH 1 O(n^2)
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int row= matrix.size();
//         int col=matrix[0].size();
//         int i=row;
//         while(i--)
//         {
//             if(target==matrix[i][0])
//                 return true;
            
//             if(target>matrix[i][0])
//             {
//                 for(int j=0;j<col;j++)
//                 {
//                     if(target==matrix[i][j])
//                         return true;
//                 }
//             }
//         }
//         return false;
//     }
    
    
    //APPROACH 2 o(logn)
     bool searchMatrix(vector<vector<int>>& matrix, int target) {
         int row= matrix.size();
         int col=matrix[0].size();
         int start=0;
         int end = row * col-1;
         int mid = start+ (end-start)/2;
         
         while(start<=end)
         {
             int element = matrix[mid/col][mid%col];
             if(target==element)
             {
                return 1;
             }
             if(target<element){
                end=mid-1;
             }
             else
             {
                start=mid+1;
             }
             mid=start+ (end-start)/2;
         }
         return 0;
     
     }
    
};