class Solution {
public:
    
    //we are going to use binary search for this. 
    //peak means the left sub array elements are in increasing order and the right subarray ele are in decreasing order.
    
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int start =0, end = arr.size()-1;
        int mid = start +(end-start)/2;
        
        //if we did start <= end , that would make us compare mid to its adjacent positions even when the end and start have collided to find the peak ele.
        
        while(start<end){
            if(arr[mid]<arr[mid+1]){
                start = mid+1;
            }
            
            //if we did end = mid -1, what if this mid ele was the peak ele ? so we only shift the end to mid and again check if the array is still a decreasing one or increasing one.
            else
                end = mid;
            mid = start+(end-start)/2;
        }
        //returning the index of the peak ele, we could also return end because now the start and end both point to same ele.
        return start;
        //or return end;
    }
};