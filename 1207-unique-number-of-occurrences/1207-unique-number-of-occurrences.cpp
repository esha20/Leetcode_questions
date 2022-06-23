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

/*
        ANOTHER SOLUTION WITHOUT USING MAP AND SET
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n=arr.size();
        vector <int> store_count(n,0);
        std::sort(arr.begin(), arr.end());
        int j=0,count=0;
        
        for(int i=1;i<n;i++)
        {
            if (arr[i]==arr[i-1] || (i+1)>n)
            {
                store_count[j]+=1;
            }
            else
            {
                j++;
                count++;
        
            }
        }
        store_count.resize(count);
        std::sort(store_count.begin(),store_count.end());
        for(int i=0;i<store_count.size();i++)
        {
            if(store_count[i]==store_count[i+1])
                return false;
        }
        return true;
    }
};

*/