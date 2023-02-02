class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map <char,int> dict;
        
        for(int i=0;i<order.length();i++){
            dict[order[i]] = i;
        }
        
        for(int i=0;i<words.size()-1;i++){
            string curr = words[i];
            string next = words[i+1];
                int idx =0;
                // if(next.size() < curr.size())
                // return false;
                while(curr[idx] == next[idx] && idx != curr.size()-1){
                    if(idx==next.size()-1)    return false;
                    idx++;
                }
                if(dict[curr[idx]] > dict[next[idx]]) return false;
            }
        
        return true;
    }
};