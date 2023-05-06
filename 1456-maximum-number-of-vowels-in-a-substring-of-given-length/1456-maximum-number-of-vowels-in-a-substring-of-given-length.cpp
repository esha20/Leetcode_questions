class Solution {
public:
    int maxVowels(string s, int k) {
        int cnt =0, maxcnt =0;
        
        for(int i=0;i<k;i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')   cnt++;
        }
        maxcnt=max(maxcnt,cnt);
        int j = k,i=0;
        while(j<=s.length()){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')   {
                cnt--;
            }
            if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u')   {
                cnt++;
            }
            i++;
            j++;
            maxcnt = max(maxcnt,cnt);
        }
        return maxcnt;
    }
};