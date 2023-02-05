class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector <int> ans;
        
        if(s.length() < p.length())     return ans;
            
        map<int,int> freqs;
        map<int,int> freqp;
        
        for(int i =0;i<p.length();i++){
            freqs[s[i]]++;
            freqp[p[i]]++;
        }
        
        int i=0, j = p.length();
        
        while(j <= s.size()){
           
            if(freqs==freqp){
                ans.push_back(i);
            }
            
            freqs[s[i]]--;
            if(freqs[s[i]] == 0){
                freqs.erase(s[i]);
            }
            
            freqs[s[j]]++;
            
            i++;
            j++;
        }
        return ans;
    }
};