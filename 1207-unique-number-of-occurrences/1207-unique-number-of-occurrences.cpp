class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> m;  
        unordered_set<int> count;
        
        for(auto i:arr)
        {
            m[i]++;     //key of map becomes the element itself and the value is the frequency of that particular element since the map cannot have duplicate values.
        }
        for (auto i : m)
        {
            count.insert(i.second);     
            //storing the frequency of each element in the set named count.
            //since set only stores unique elements so if one of the values is duplicate, it rejects it.
        }
        return count.size()==m.size();
    }
};