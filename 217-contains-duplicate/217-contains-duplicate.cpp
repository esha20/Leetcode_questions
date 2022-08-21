class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map <int,int> m;
        for (int i =0; i<nums.size();i++)
        {
            m[nums[i]]++;
            //for each key we count the elements and then we have the frequency.
        }
        for(auto x: m)
        {
            //if the frequency is greater than 1 , return true. duplicates present
            if(x.second > 1)
                return true;
        }
        return false;
    }
};