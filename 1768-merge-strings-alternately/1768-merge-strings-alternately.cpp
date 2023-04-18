class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        int size1= word1.size();
        int size2 = word2.size();
        int size = min(size1, size2);
        for(int i=0;i<size;i++){
            if(size1 != 0 && size2!= 0){
                ans+=word1[i];   size1--;   
                ans+=word2[i];   size2--;
            }
        }
        if(size1!=0){
            while(size1!=0){
            ans += word1[word1.size()-size1];   size1--;
            }
        }
        else if (size2 != 0){
            while(size2!=0){
            ans += word2[word2.size()-size2];   size2--;
            }
        }
        return ans;
    }
};