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
    //we could have also used the map with int and bool values , ie if the number has occured once , mark it true and at last check if there are true bool values for integers of array 
};