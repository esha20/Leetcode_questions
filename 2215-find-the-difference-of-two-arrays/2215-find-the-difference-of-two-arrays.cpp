class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set <int> s1,s2;
        vector<vector<int>> Fans;
        
        for(int i=0;i<nums1.size();i++){
            s1.insert(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++){
            s2.insert(nums2[i]);
        }
        
        vector<int> ans1,ans2;
        
        for(int i=0;i<nums1.size();i++){
            if(s2.find(nums1[i]) == s2.end()){
                ans1.push_back(nums1[i]);
                //to avoid duplicate elements
                s2.insert(nums1[i]);
            }
        }
        for(int i=0;i<nums2.size();i++){
            if(s1.find(nums2[i]) == s1.end()){
                ans2.push_back(nums2[i]);
                //to avoid duplicate elements
                s1.insert(nums2[i]);
            }
        }
        Fans.push_back(ans1);
        Fans.push_back(ans2);
        return Fans;
    }
};