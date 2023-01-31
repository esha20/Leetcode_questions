class Solution {
public:
    int mySqrt(int x) {
        
        //long long int because int was out of range for some values.
        long long int start=0, end = x, ans = 1;
        
        //Thought of making the end as x/2 because the square root of any number is far less than the half of the number
        //but that fails for x=1;
        long long int mid = start+(end-start)/2;
        
        while(start<=end){
            
            //returning if mid is the sqrt. i.e. if mid * mid is equal to x
            if(mid*mid == x)
                return mid;
            
            else if(mid*mid > x)
                end = mid-1;
            
            else{
                
                //storing the ans because it said to give the floor value if the sqrt is not found.
                start = mid+1;
                ans = mid;
            }
            
            //calculating the new mid.
            mid = start+(end-start)/2;
        }
        return ans;
    }
};