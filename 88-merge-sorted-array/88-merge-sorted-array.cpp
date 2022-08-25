class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1, j=n-1, k=m+n-1;
        
        // i and j are pointing to the last numbers of the rrays whihch are to be sorted.
        // k is poinitng to the last index of nums1 
        
        while(i>=0 && j>=0){
            // if either of the two vectors reach their end, the comparison will not be possible
            
            if(nums1[i]<nums2[j])
                nums1[k--]=nums2[j--];
            
            
            else
                nums1[k--]=nums1[i--];
            
            //simply compare and shift the one with higher value to the kth popsition since we are working from the end of the array.
        }
        
        //this loop works when the nums1 array is traversed but the nums2 array is left
        while(j>=0)
        {
            nums1[k--]= nums2[j--];
        }
    }
};