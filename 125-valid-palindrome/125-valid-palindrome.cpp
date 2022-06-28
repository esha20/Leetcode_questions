class Solution {
private:
bool isvalid(char ch)
{
    if((ch >= 'a' && ch <='z')||(ch>='0' && ch<='9')||(ch >='A' && ch<='Z'))
        return 1;
    return 0;
}
char tolowercase(char ch)
{
    if((ch >= 'a' && ch <='z')||(ch>='0' && ch<='9'))
        return ch;
    else{
      char new_char = ch -'A'+'a';
      return new_char;  
    }
    
}
bool checkpalin(string name)
{
int start=0, end=name.length()-1 ;
while (start<=end)
{
    if(name[start]!=name[end]){
        return 0;
    }
    else{
        start++;
        end--;
    }
}
return 1;
}
    
public:
    bool isPalindrome(string s) {
        string ans="";
        
        for(int i=0;i<s.length();i++)
        {
            if(isvalid(s[i])){
                ans.push_back(s[i]);
            }
        }
        
        for(int j=0;j<ans.length();j++)
        {
            ans[j]=tolowercase(ans[j]);
        }
        return checkpalin(ans);
    }
};