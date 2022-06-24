class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        vector <int> freq(n+1,0), ans;  
        //we can declare the frequency array of size nums.size()+1 since the question says that the input integers areof range 1 to n only where n is the size of the array.
        
        for (auto i : nums)
            freq[i]++;         
        //for filling out the freq array which we have earlier initialised with 0.
        
        for (int i=0;i<n+1;i++)
            
        {
            if (freq[i]==2)         //since an integer can atmost appear twice.
              ans.push_back(i);   
        }
        return ans;
    }
};