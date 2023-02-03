class Solution {
public:
    string convert(string s, int rows) {
        if(rows == 1)       return s;
        string store[rows];
        int count = 0;         //index to see where to store the string
        bool flag = true;      //keeping track of the direction of the insertion.
        for(int i=0;i<s.length();i++){
            
            if(count == rows-1){
                flag = false;
            }
            if(count == 0){
                flag = true;
            }
            if(flag == true){
                store[count]+=s[i];
                count++;
            }
            else if(flag == false ){
                store[count]+=s[i];
                count--;
            }
        }
        
        string res;
        for(int i=0;i<rows;i++){
            res+=store[i];
        }
        
        return res;
    }
};